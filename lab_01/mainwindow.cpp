#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Динь Вьет Ань - ИУ7И-44Б");

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, WIN_X, WIN_Y);

    command req;
    req.task_f = START;
    req.draw_f.scene = scene;
    inquiry(req);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int transf_show(command req, Ui::MainWindow *ui)
{
    int rc = inquiry(req);
    if (rc != SUCCESS)
        return rc;
    else
        rc = start_draw(ui);

    return rc;
}

int start_draw(Ui::MainWindow *ui)
{
    drawer draw_init;

    draw_init.scene = ui->graphicsView->scene();
    draw_init.h = ui->graphicsView->height();
    draw_init.w = ui->graphicsView->width();

    command req;
    req.task_f = DRAW;
    req.draw_f = draw_init;

    int rc = inquiry(req);
    return rc;
}

void MainWindow::on_pushButton_name_clicked()
{
    command req;
    req.task_f = DOWNLOAD_FILE;

    QString text = ui->lineEdit_file->text();

    std::string str = text.toStdString();
    req.filename = str.c_str();

    int rc = transf_show(req, ui);
    if (rc != SUCCESS)
        show_error(rc);
}

void MainWindow::on_pushButton_move_clicked()
{
    command req;
    req.task_f = MOVE;

    req.move_f.dx = ui->doubleSpinBox_movex->value();
    req.move_f.dy = ui->doubleSpinBox_movey->value();
    req.move_f.dz = ui->doubleSpinBox_movez->value();

    int rc = transf_show(req, ui);
    if (rc != SUCCESS)
        show_error(rc);
}

void MainWindow::on_pushButton_turn_clicked()
{
    command req;
    req.task_f = TURN;

    req.turn_f.alpha_x = ui->doubleSpinBox_turnx->value();
    req.turn_f.alpha_y = ui->doubleSpinBox_turny->value();
    req.turn_f.alpha_z = ui->doubleSpinBox_turnz->value();

    int rc = transf_show(req, ui);
    if (rc != SUCCESS)
        show_error(rc);
}

void MainWindow::on_pushButton_scale_clicked()
{
    command req;
    req.task_f = SCALE;
    req.scale_f.kx = ui->doubleSpinBox_kx->value();
    req.scale_f.ky = ui->doubleSpinBox_ky->value();
    req.scale_f.kz = ui->doubleSpinBox_kz->value();

    int rc = transf_show(req, ui);
    if (rc != SUCCESS)
        show_error(rc);
}
