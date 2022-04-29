#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::cout << "konstructor" <<std::endl;
    ui->setupUi(this);

    ui->statusbar->showMessage("Лабораторная работа №1, Козлова Ирина ИУ7-42Б");
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, WIN_X, WIN_Y);

    request req;
    req.task_f = START;
    req.draw_f.scene = scene;
    inquiry(req);
}

MainWindow::~MainWindow()
{
    request req;
    req.task_f = EXIT;
    inquiry(req);
    delete ui;
}

error_code transf_show(request req, Ui::MainWindow *ui)
{
    error_code rc = (error_code)inquiry(req);
    if (rc != OK)
        return rc;
    else
        rc = start_draw(ui);

    return rc;
}

error_code start_draw(Ui::MainWindow *ui)
{
    drawer draw_init;

    draw_init.scene = ui->graphicsView->scene();
    draw_init.h = ui->graphicsView->height();
    draw_init.w = ui->graphicsView->width();

    request req;
    req.task_f = DRAW;
    req.draw_f = draw_init;

    error_code rc = (error_code)inquiry(req);
    return rc;
}


void MainWindow::on_pushButton_name_clicked()
{
    request req;
    req.task_f = DOWNLOAD_FILE;

    QString text = ui->lineEdit_file->text();

    std::string str = text.toStdString();
    req.filename = str.c_str();

    std::cout << req.filename <<std::endl;

    error_code rc = transf_show(req, ui);
    if (rc != OK)
    {
        messege_of_error(rc);
    }
}


void MainWindow::on_pushButton_move_clicked()
{
    request req;
    req.task_f = MOVE;

    req.move_f.dx = ui->doubleSpinBox_movex->value();
    req.move_f.dy = ui->doubleSpinBox_movey->value();
    req.move_f.dz = ui->doubleSpinBox_movez->value();

    error_code rc = transf_show(req, ui);
    if (rc != OK)
    {
        messege_of_error(rc);
    }
}


void MainWindow::on_pushButton_turn_clicked()
{
    request req;
    req.task_f = TURN;

    req.turn_f.alpha_x = ui->doubleSpinBox_turnx->value();
    req.turn_f.alpha_y = ui->doubleSpinBox_turny->value();
    req.turn_f.alpha_z = ui->doubleSpinBox_turnz->value();

    error_code rc = transf_show(req, ui);
    if (rc != OK)
    {
        messege_of_error(rc);
    }
}

void MainWindow::on_pushButton_scale_clicked()
{
    request req;
    req.task_f = SCALE;
    req.scale_f.kx = ui->doubleSpinBox_kx->value();
    req.scale_f.ky = ui->doubleSpinBox_ky->value();
    req.scale_f.kz = ui->doubleSpinBox_kz->value();

    error_code rc = transf_show(req, ui);
    if (rc != OK)
    {
        messege_of_error(rc);
    }
}
