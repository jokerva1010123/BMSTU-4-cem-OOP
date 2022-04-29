#include "mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QScreen>
#include "config.h"

#define CONFIG "config.cfg"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    auto c = ConfigCreator().get_config(nullptr);

//    if (c->what_lib() == AbstractConfig::Qt)
//    {
    MainWindow window;
//    window.setGeometry(QStyle::alignedRect(
//            Qt::LeftToRight, Qt::AlignCenter, window.size(),
//            QGuiApplication::primaryScreen()->availableGeometry()));
    window.show();

    return QApplication::exec();
//    }
}
