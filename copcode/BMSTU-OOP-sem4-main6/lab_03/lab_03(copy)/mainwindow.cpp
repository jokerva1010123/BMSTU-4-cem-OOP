#include "mainwindow.h"
#include <QFileDialog>
#include "ui_mainwindow.h"
#include "qt_factory.h"
#include <cstddef>
#include <fstream>
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_scene();
    facade_ = std::make_shared<Facade>(Facade());

    connect(ui->load_button, &QPushButton::clicked,
            this, &MainWindow::on_load_button_clicked);

    connect(ui->delete_model, &QPushButton::clicked,
            this, &MainWindow::on_delete_model_button_clicked);

    connect(ui->add_camera, &QPushButton::clicked,
            this, &MainWindow::on_add_camera_clicked);

    connect(ui->delete_camera, &QPushButton::clicked,
            this, &MainWindow::on_delete_camera_clicked);

    connect(ui->clear_screen, &QPushButton::clicked,
            this, &MainWindow::clean_scene);

    connect(ui->right_button, &QPushButton::clicked,
            this, &MainWindow::on_right_button_clicked);

    connect(ui->up_button, &QPushButton::clicked,
            this, &MainWindow::on_up_button_clicked);

    connect(ui->down_button, &QPushButton::clicked,
            this, &MainWindow::on_down_button_clicked);

    connect(ui->left_button, &QPushButton::clicked,
            this, &MainWindow::on_left_button_clicked);

    connect(ui->move_button, &QPushButton::clicked,
            this, &MainWindow::on_move_button_clicked);

    connect(ui->scale_button, &QPushButton::clicked,
            this, &MainWindow::on_scale_button_clicked);

    connect(ui->turn_button, &QPushButton::clicked,
            this, &MainWindow::on_turn_button_clicked);

    connect(ui->camera_choose, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::change_camera);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::resize_event(QResizeEvent *e)
{
    QWidget::resizeEvent(e);

    scene_->setSceneRect(0, 0, ui->graphicsView->width(),
                               ui->graphicsView->height());

    auto buf = ui->graphicsView->contentsRect();

    scene_->setSceneRect(0, 0, buf.width(), buf.height());
}


void MainWindow::count_cam_check()
{
    auto camera_count = std::make_shared<size_t>(0);

    CountCamera camera_command(camera_count);
    facade_->execute(camera_command);

    if (!*camera_count)
    {
        time_t time_ = time(NULL);

        throw CameraError(__FILE__,
                                typeid(*this).name(),
                                __LINE__,
                                ctime(&time_));
    }
}

void MainWindow::delete_cam_check()
{
    auto model_count = std::make_shared<size_t>(0);

    CountModel model_command(model_count);
    facade_->execute(model_command);

    auto camera_count = std::make_shared<size_t>(0);
    CountCamera camera_command(camera_count);
    facade_->execute(camera_command);

    if (*camera_count <= 1 && *model_count)
    {
        time_t time_ = time(NULL);

        throw CameraError(__FILE__,
                                typeid(*this).name(),
                                __LINE__,
                                ctime(&time_));
    }
}

void MainWindow::count_model_check()
{
    auto count = std::make_shared<size_t>(0);

    CountModel model_command(count);
    facade_->execute(model_command);

    if (!*count)
    {
        time_t time_ = time(NULL);

        throw ModelError(__FILE__,
                                typeid(*this).name(),
                                __LINE__,
                                ctime(&time_));
    }
}

void MainWindow::on_move_button_clicked()
{
    try
    {
        count_cam_check();
        count_model_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No cameras loaded.");
        return;
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No models uploaded.");
        return;
    }

    MoveModel move_command(
            ui->dx_box->value(),
            ui->dy_box->value(),
            ui->dz_box->value(),
            ui->model_choose->currentIndex());

    facade_->execute(move_command);
    updata_scene();
}


void MainWindow::on_scale_button_clicked()
{
    try
    {
        count_cam_check();
        count_model_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No cameras loaded.");
        return;
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No models uploaded.");
        return;
    }

    ScaleModel scale_command(
            ui->kx_box->value(),
            ui->ky_box->value(),
            ui->kz_box->value(),
            ui->model_choose->currentIndex());

    facade_->execute(scale_command);
    updata_scene();
}


void MainWindow::on_turn_button_clicked()
{
    try
    {
        count_cam_check();
        count_model_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No cameras loaded.");
        return;
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No models uploaded.");
        return;
    }

    RotateModel rotate_command(
            ui->ox_box->value(),
            ui->oy_box->value(),
            ui->oz_box->value(),
            ui->model_choose->currentIndex());

    facade_->execute(rotate_command);
    updata_scene();
}


void MainWindow::on_load_button_clicked()
{
    try
    {
        count_cam_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "Before adding a model, add at least one camera.");
        return;
    }

    auto t = QFileDialog::getOpenFileName();

    if (t.isNull())
    {
        return;
    }

    LoadModel load_command(t.toUtf8().data());

    try
    {
        facade_->execute(load_command);
    } catch (const FileOpenError &error)
    {
        QMessageBox::critical(nullptr, "Error", "Something went wrong while uploading the file.");
        return;
    }

    updata_scene();

    ui->model_choose->addItem(QFileInfo(t.toUtf8().data()).fileName());
    ui->model_choose->setCurrentIndex(ui->model_choose->count() - 1);
}

void MainWindow::on_delete_model_button_clicked()
{
    try
    {
        count_model_check();
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "Add at least one before deleting models.");
        return;
    }

    RemoveModel remove_command(ui->model_choose->currentIndex());
    facade_->execute(remove_command);

    ui->model_choose->removeItem(ui->model_choose->currentIndex());

    updata_scene();
}


void MainWindow::set_scene()
{
    scene_ = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene_);

    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto r = ui->graphicsView->contentsRect();
    scene_->setSceneRect(0, 0, r.width(), r.height());

    std::shared_ptr<AbstractFactory> factory(new QTFactory(scene_));

    drawer_ = factory->create_graphics();
}


void MainWindow::updata_scene()
{
    DrawScene draw_command(drawer_);

    facade_->execute(draw_command);
}

void MainWindow::clean_scene()
{
    try
    {
        count_model_check();
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "Add at least one before deleting models.");
        return;
    }

    for (int i = ui->model_choose->count() - 1; i >= 0; --i)
    {
        RemoveModel remove_command(i);
        facade_->execute(remove_command);

        ui->model_choose->removeItem(i);
    }

    updata_scene();
}

void MainWindow::on_add_camera_clicked()
{
    auto r = ui->graphicsView->contentsRect();
    AddCamera camera_command(r.width() / 2.0, r.height() / 2.0, 0.0);
    facade_->execute(camera_command);

    updata_scene();


    auto c = ui->camera_choose;

    if (c->count() == 0)
        c->addItem(QString::number(1));
    else
        c->addItem(QString::number(
                c->itemText(c->count() - 1).toInt() + 1));

    ui->camera_choose->setCurrentIndex(ui->camera_choose->count() - 1);
}

void MainWindow::on_delete_camera_clicked()
{
    try
    {
        count_cam_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "Before deleting a camera, add at least one.");
        return;
    }

    try
    {
        delete_cam_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "Before removing the camera, you must remove the remaining models.");
        return;
    }

    RemoveCamera remove_command(ui->camera_choose->currentIndex());
    facade_->execute(remove_command);

    ui->camera_choose->removeItem(ui->camera_choose->currentIndex());

    try
    {
        count_cam_check();
    } catch (const CameraError &error)
    {
        return;
    }

    updata_scene();
}



void MainWindow::change_camera()
{
    try
    {
        count_cam_check();
    } catch (const CameraError &error)
    {
        return;
    }

    SetCamera camera_command(ui->camera_choose->currentIndex());
    facade_->execute(camera_command);

    updata_scene();
}


void MainWindow::on_right_button_clicked()
{
    try
    {
        count_cam_check();
        count_model_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No cameras loaded.");
        return;
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No models uploaded.");
        return;
    }

    MoveCamera camera_command(ui->camera_choose->currentIndex(), 10, 0);
    facade_->execute(camera_command);

    updata_scene();
}


void MainWindow::on_up_button_clicked()
{
    try
    {
        count_cam_check();
        count_model_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No cameras loaded.");
        return;
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No models uploaded.");
        return;
    }

    MoveCamera camera_command(ui->camera_choose->currentIndex(), 0, -10);
    facade_->execute(camera_command);


    updata_scene();
}


void MainWindow::on_down_button_clicked()
{
    try
    {
        count_cam_check();
        count_model_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No cameras loaded.");
        return;
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No models uploaded.");
        return;
    }

    MoveCamera camera_command(ui->camera_choose->currentIndex(), 0, 10);
    facade_->execute(camera_command);

    updata_scene();
}

void MainWindow::on_left_button_clicked()
{
    try
    {
        count_cam_check();
        count_model_check();
    } catch (const CameraError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No cameras loaded.");
        return;
    } catch (const ModelError &error)
    {
        QMessageBox::critical(nullptr, "Error", "No models uploaded.");
        return;
    }

    MoveCamera camera_command(ui->camera_choose->currentIndex(), -10, 0);
    facade_->execute(camera_command);

    updata_scene();
}

//std::shared_ptr<BaseDrawer> MainWindow::DrawDirector::get_drawer(const char *fp, std::shared_ptr<AbstractFactory> &f)
//{
//     MainWindow obj;
//     if (obj.readConfigFile(fp) == "Qt")
//     {
//         printf("QT");
//        this->_scene_view->clear();
////        f = new QTFactory(this->_scene_view);
//        auto drawer = f->create_graphics();


//        return drawer;
//     }

//     return nullptr;
//}
