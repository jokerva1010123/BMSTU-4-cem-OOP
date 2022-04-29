#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QMessageBox"

#include "systemcontroller.h"
#include "elevator.h"
#include "exeptions.h"

const int FloorCount = 5;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    system = new SystemController(0, FloorCount);
    Lift = new Elevator(0);
    system->addLiftConnection(Lift);
    QObject::connect(system, SIGNAL(floorChandged(int)), this, SLOT(floorChandged(int)), Qt::QueuedConnection);
    QObject::connect(Lift, SIGNAL(openDoors()), this, SLOT(doorsOpened()));
    QObject::connect(Lift, SIGNAL(doorsClosed()), this, SLOT(doorsAreClosed()));
    QObject::connect(Lift, SIGNAL(openingDoors()), this, SLOT(doorsOpening()));
    QObject::connect(Lift, SIGNAL(closingDoors()), this, SLOT(doorsClosing()));
}

MainWindow::~MainWindow()
{
    delete system;
    delete Lift;
    delete ui;
}

void MainWindow::floorChandged(int floorNumber)
{
    ui->labelFloor->setText("Elevator is on the "+QString::number(floorNumber + 1)+ " floor");
    ui->labelFloor->repaint();
}
void MainWindow::doorsOpening()
{
//    QMessageBox::information(this, "Doors", "Doors are opening", QMessageBox::Ok);
    ui->labelDoors->setText(QString::fromLocal8Bit("Doors are opening"));
    ui->labelDoors->repaint();
}

void MainWindow::doorsClosing()
{
 //   QMessageBox::information(this, "Doors", "Doors are closing", QMessageBox::Ok);
    ui->labelDoors->setText(QString::fromLocal8Bit("Doors are closing"));
    ui->labelDoors->repaint();
}
void MainWindow::doorsOpened()
{
 //   QMessageBox::information(this, "Doors", "Doors are opened", QMessageBox::Ok);
    ui->labelDoors->setText(QString::fromLocal8Bit("Doors are opened"));
    ui->labelDoors->repaint();
}

void MainWindow::doorsAreClosed()
{
 //   QMessageBox::information(this, "Doors", "Doors are closed", QMessageBox::Ok);
    ui->labelDoors->setText(QString::fromLocal8Bit("Doors are closed"));
    ui->labelDoors->repaint();
}

void MainWindow::on_btn1Up_clicked()
{
    try
    {
        system->upPushed(0);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}

void MainWindow::on_btn2Down_clicked()
{
    try
    {
        system->downPushed(9);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}

void MainWindow::on_btn2Up_clicked()
{
    try
    {
        system->upPushed(1);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}

void MainWindow::on_btn3Down_clicked()
{
    try
    {
        system->downPushed(2);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}

void MainWindow::on_btn3Up_clicked()
{
    try
    {
        system->upPushed(2);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}

void MainWindow::on_btn4Down_clicked()
{
    try
    {
        system->downPushed(3);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}

void MainWindow::on_btn4Up_clicked()
{
    try
    {
        system->upPushed(3);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}

void MainWindow::on_btn5Down_clicked()
{ 
    try
    {
        system->downPushed(4);
    }
    catch (BaseExeption& e)
    {
        QMessageBox::warning(this, "ERROR", e.ErrorMsg(), QMessageBox::Ok);
    }
}
