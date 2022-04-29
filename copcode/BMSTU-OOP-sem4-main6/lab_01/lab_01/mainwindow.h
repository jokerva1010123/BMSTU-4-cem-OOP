#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "my_error.h"
#include "menu.h"

#define WIN_X 600
#define WIN_Y 500

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_name_clicked();

    void on_pushButton_scale_clicked();

    void on_pushButton_turn_clicked();

    void on_pushButton_move_clicked();

private:
    Ui::MainWindow *ui;
};

error_code transf_show(request req, Ui::MainWindow *ui);
error_code start_draw(Ui::MainWindow *ui);

#endif // MAINWINDOW_H
