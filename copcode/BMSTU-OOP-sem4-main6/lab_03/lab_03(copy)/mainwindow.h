#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "base_drawer.h"
#include "base_command.h"
#include "camera_command.h"
#include "model_command.h"
#include "scene_command.h"
#include "errors.hpp"
#include "facade.h"
#include "ui_mainwindow.h"
#include "qt_factory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void set_scene();
    void updata_scene();

    void clean_scene();
    void count_cam_check();
    void delete_cam_check();
    void count_model_check();




protected:
    void resize_event(QResizeEvent *e);

private:
    void change_camera();
    void on_move_button_clicked();
    void on_scale_button_clicked();
    void on_turn_button_clicked();
    void on_load_button_clicked();
    void on_delete_model_button_clicked();
    void on_add_camera_clicked();
    void on_delete_camera_clicked();
    void on_right_button_clicked();
    void on_up_button_clicked();
    void on_down_button_clicked();
    void on_left_button_clicked();

private:
    friend class DrawDirector;
    Ui::MainWindow *ui;
    QGraphicsScene *scene_;

    std::shared_ptr<Facade> facade_;
    std::shared_ptr<BaseDrawer> drawer_;

    DrawDirector director;

    size_t index_model;
    size_t index_camera;

    std::string readConfigFile(const char *filename);
};
#endif // MAINWINDOW_H
