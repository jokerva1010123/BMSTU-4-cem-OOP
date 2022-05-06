/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLineEdit *X_E;
    QLineEdit *Z_E;
    QLineEdit *Y_E;
    QPushButton *pushButton_7;
    QLineEdit *Cam_E;
    QLineEdit *X_E_2;
    QLineEdit *Z_E_2;
    QLineEdit *Y_E_2;
    QLineEdit *X_E_3;
    QLineEdit *Z_E_3;
    QLineEdit *Y_E_3;
    QLineEdit *N_L;
    QLineEdit *N_L_2;
    QLineEdit *N_L_3;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1246, 843);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 771, 811));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(890, 42, 231, 41));
        QFont font;
        font.setPointSize(15);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(890, 90, 231, 41));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(890, 142, 231, 41));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(890, 470, 231, 41));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(890, 300, 231, 41));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(880, 630, 251, 41));
        pushButton_6->setFont(font);
        X_E = new QLineEdit(centralwidget);
        X_E->setObjectName(QString::fromUtf8("X_E"));
        X_E->setGeometry(QRect(820, 250, 91, 31));
        QFont font1;
        font1.setPointSize(16);
        X_E->setFont(font1);
        Z_E = new QLineEdit(centralwidget);
        Z_E->setObjectName(QString::fromUtf8("Z_E"));
        Z_E->setGeometry(QRect(1100, 250, 91, 31));
        Z_E->setFont(font1);
        Y_E = new QLineEdit(centralwidget);
        Y_E->setObjectName(QString::fromUtf8("Y_E"));
        Y_E->setGeometry(QRect(960, 250, 91, 31));
        Y_E->setFont(font1);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(880, 760, 251, 41));
        pushButton_7->setFont(font);
        Cam_E = new QLineEdit(centralwidget);
        Cam_E->setObjectName(QString::fromUtf8("Cam_E"));
        Cam_E->setGeometry(QRect(960, 710, 81, 31));
        X_E_2 = new QLineEdit(centralwidget);
        X_E_2->setObjectName(QString::fromUtf8("X_E_2"));
        X_E_2->setGeometry(QRect(820, 420, 91, 31));
        X_E_2->setFont(font1);
        Z_E_2 = new QLineEdit(centralwidget);
        Z_E_2->setObjectName(QString::fromUtf8("Z_E_2"));
        Z_E_2->setGeometry(QRect(1100, 420, 91, 31));
        Z_E_2->setFont(font1);
        Y_E_2 = new QLineEdit(centralwidget);
        Y_E_2->setObjectName(QString::fromUtf8("Y_E_2"));
        Y_E_2->setGeometry(QRect(960, 420, 81, 31));
        Y_E_2->setFont(font1);
        X_E_3 = new QLineEdit(centralwidget);
        X_E_3->setObjectName(QString::fromUtf8("X_E_3"));
        X_E_3->setGeometry(QRect(820, 580, 91, 31));
        X_E_3->setFont(font1);
        Z_E_3 = new QLineEdit(centralwidget);
        Z_E_3->setObjectName(QString::fromUtf8("Z_E_3"));
        Z_E_3->setGeometry(QRect(1100, 580, 91, 31));
        Z_E_3->setFont(font1);
        Y_E_3 = new QLineEdit(centralwidget);
        Y_E_3->setObjectName(QString::fromUtf8("Y_E_3"));
        Y_E_3->setGeometry(QRect(960, 580, 81, 31));
        Y_E_3->setFont(font1);
        N_L = new QLineEdit(centralwidget);
        N_L->setObjectName(QString::fromUtf8("N_L"));
        N_L->setGeometry(QRect(960, 210, 91, 31));
        N_L->setFont(font1);
        N_L_2 = new QLineEdit(centralwidget);
        N_L_2->setObjectName(QString::fromUtf8("N_L_2"));
        N_L_2->setGeometry(QRect(960, 380, 81, 31));
        N_L_2->setFont(font1);
        N_L_3 = new QLineEdit(centralwidget);
        N_L_3->setObjectName(QString::fromUtf8("N_L_3"));
        N_L_3->setGeometry(QRect(960, 540, 81, 31));
        N_L_3->setFont(font1);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(780, 350, 491, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(770, 520, 501, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(770, 690, 491, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1246, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\321\203", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\276\320\261\321\212\320\265\320\272\321\202", nullptr));
        X_E->setText(QApplication::translate("MainWindow", "0", nullptr));
        Z_E->setText(QApplication::translate("MainWindow", "0", nullptr));
        Y_E->setText(QApplication::translate("MainWindow", "0", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\272\320\260\320\274\320\265\321\200\321\203", nullptr));
        X_E_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        Z_E_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        Y_E_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        X_E_3->setText(QApplication::translate("MainWindow", "1", nullptr));
        Z_E_3->setText(QApplication::translate("MainWindow", "1", nullptr));
        Y_E_3->setText(QApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
