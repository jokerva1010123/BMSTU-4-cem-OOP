#pragma once

#include <QMainWindow>

class SystemController;
class Elevator;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void floorChandged(int floorNumber);
    void doorsOpened();
    void doorsAreClosed();
    void doorsOpening();
    void doorsClosing();

private slots:
    void on_btn1Up_clicked();
    void on_btn2Down_clicked();
    void on_btn2Up_clicked();
    void on_btn3Down_clicked();
    void on_btn3Up_clicked();
    void on_btn4Down_clicked();
    void on_btn4Up_clicked();
    void on_btn5Down_clicked();

private:
    Ui::MainWindow *ui;
    Elevator* Lift;
    SystemController* system;
};
