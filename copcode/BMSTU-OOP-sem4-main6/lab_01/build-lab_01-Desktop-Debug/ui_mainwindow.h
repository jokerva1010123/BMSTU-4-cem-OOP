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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_chname;
    QHBoxLayout *horizontalLayout_name;
    QLabel *label_name;
    QLineEdit *lineEdit_file;
    QPushButton *pushButton_name;
    QSpacerItem *verticalSpacer;
    QLabel *label_scale;
    QVBoxLayout *verticalLayout_scale;
    QGridLayout *gridLayout_scale;
    QHBoxLayout *horizontalLayout_scale_kx;
    QLabel *label_kx;
    QDoubleSpinBox *doubleSpinBox_kx;
    QHBoxLayout *horizontalLayout_scale_ky;
    QLabel *label_ky;
    QDoubleSpinBox *doubleSpinBox_ky;
    QHBoxLayout *horizontalLayout_scale_kz;
    QLabel *label_kz;
    QDoubleSpinBox *doubleSpinBox_kz;
    QPushButton *pushButton_scale;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_turn;
    QGridLayout *gridLayout_turn;
    QHBoxLayout *horizontalLayout_turny;
    QLabel *label_turny;
    QDoubleSpinBox *doubleSpinBox_turny;
    QHBoxLayout *horizontalLayout_turnx;
    QLabel *label_turnx;
    QDoubleSpinBox *doubleSpinBox_turnx;
    QHBoxLayout *horizontalLayout_turnz;
    QLabel *label_turnz;
    QDoubleSpinBox *doubleSpinBox_turnz;
    QPushButton *pushButton_turn;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_move;
    QGridLayout *gridLayout_move;
    QHBoxLayout *horizontalLayout_movez;
    QLabel *label_movez;
    QDoubleSpinBox *doubleSpinBox_movez;
    QHBoxLayout *horizontalLayout_movex;
    QLabel *label_movex;
    QDoubleSpinBox *doubleSpinBox_movex;
    QHBoxLayout *horizontalLayout_movey;
    QLabel *label_movey;
    QDoubleSpinBox *doubleSpinBox_movey;
    QPushButton *pushButton_move;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1251, 774);
        MainWindow->setMinimumSize(QSize(1251, 774));
        MainWindow->setMaximumSize(QSize(1251, 774));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(440, 10, 801, 711));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 428, 711));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_chname = new QLabel(verticalLayoutWidget);
        label_chname->setObjectName(QString::fromUtf8("label_chname"));
        QFont font;
        font.setPointSize(13);
        label_chname->setFont(font);

        verticalLayout->addWidget(label_chname);

        horizontalLayout_name = new QHBoxLayout();
        horizontalLayout_name->setObjectName(QString::fromUtf8("horizontalLayout_name"));
        label_name = new QLabel(verticalLayoutWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        horizontalLayout_name->addWidget(label_name);

        lineEdit_file = new QLineEdit(verticalLayoutWidget);
        lineEdit_file->setObjectName(QString::fromUtf8("lineEdit_file"));

        horizontalLayout_name->addWidget(lineEdit_file);


        verticalLayout->addLayout(horizontalLayout_name);

        pushButton_name = new QPushButton(verticalLayoutWidget);
        pushButton_name->setObjectName(QString::fromUtf8("pushButton_name"));

        verticalLayout->addWidget(pushButton_name);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_scale = new QLabel(verticalLayoutWidget);
        label_scale->setObjectName(QString::fromUtf8("label_scale"));
        label_scale->setFont(font);

        verticalLayout->addWidget(label_scale);

        verticalLayout_scale = new QVBoxLayout();
        verticalLayout_scale->setObjectName(QString::fromUtf8("verticalLayout_scale"));
        gridLayout_scale = new QGridLayout();
        gridLayout_scale->setObjectName(QString::fromUtf8("gridLayout_scale"));
        horizontalLayout_scale_kx = new QHBoxLayout();
        horizontalLayout_scale_kx->setObjectName(QString::fromUtf8("horizontalLayout_scale_kx"));
        label_kx = new QLabel(verticalLayoutWidget);
        label_kx->setObjectName(QString::fromUtf8("label_kx"));

        horizontalLayout_scale_kx->addWidget(label_kx);

        doubleSpinBox_kx = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_kx->setObjectName(QString::fromUtf8("doubleSpinBox_kx"));
        doubleSpinBox_kx->setMinimum(-100.000000000000000);

        horizontalLayout_scale_kx->addWidget(doubleSpinBox_kx);


        gridLayout_scale->addLayout(horizontalLayout_scale_kx, 2, 0, 1, 1);

        horizontalLayout_scale_ky = new QHBoxLayout();
        horizontalLayout_scale_ky->setObjectName(QString::fromUtf8("horizontalLayout_scale_ky"));
        label_ky = new QLabel(verticalLayoutWidget);
        label_ky->setObjectName(QString::fromUtf8("label_ky"));

        horizontalLayout_scale_ky->addWidget(label_ky);

        doubleSpinBox_ky = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_ky->setObjectName(QString::fromUtf8("doubleSpinBox_ky"));
        doubleSpinBox_ky->setMinimum(-100.000000000000000);

        horizontalLayout_scale_ky->addWidget(doubleSpinBox_ky);


        gridLayout_scale->addLayout(horizontalLayout_scale_ky, 3, 0, 1, 1);

        horizontalLayout_scale_kz = new QHBoxLayout();
        horizontalLayout_scale_kz->setObjectName(QString::fromUtf8("horizontalLayout_scale_kz"));
        label_kz = new QLabel(verticalLayoutWidget);
        label_kz->setObjectName(QString::fromUtf8("label_kz"));

        horizontalLayout_scale_kz->addWidget(label_kz);

        doubleSpinBox_kz = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_kz->setObjectName(QString::fromUtf8("doubleSpinBox_kz"));
        doubleSpinBox_kz->setMinimum(-100.000000000000000);

        horizontalLayout_scale_kz->addWidget(doubleSpinBox_kz);


        gridLayout_scale->addLayout(horizontalLayout_scale_kz, 4, 0, 1, 1);


        verticalLayout_scale->addLayout(gridLayout_scale);


        verticalLayout->addLayout(verticalLayout_scale);

        pushButton_scale = new QPushButton(verticalLayoutWidget);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));

        verticalLayout->addWidget(pushButton_scale);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_turn = new QLabel(verticalLayoutWidget);
        label_turn->setObjectName(QString::fromUtf8("label_turn"));
        label_turn->setFont(font);

        verticalLayout->addWidget(label_turn);

        gridLayout_turn = new QGridLayout();
        gridLayout_turn->setObjectName(QString::fromUtf8("gridLayout_turn"));
        horizontalLayout_turny = new QHBoxLayout();
        horizontalLayout_turny->setObjectName(QString::fromUtf8("horizontalLayout_turny"));
        label_turny = new QLabel(verticalLayoutWidget);
        label_turny->setObjectName(QString::fromUtf8("label_turny"));

        horizontalLayout_turny->addWidget(label_turny);

        doubleSpinBox_turny = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_turny->setObjectName(QString::fromUtf8("doubleSpinBox_turny"));
        doubleSpinBox_turny->setMinimum(-100.000000000000000);

        horizontalLayout_turny->addWidget(doubleSpinBox_turny);


        gridLayout_turn->addLayout(horizontalLayout_turny, 1, 0, 1, 1);

        horizontalLayout_turnx = new QHBoxLayout();
        horizontalLayout_turnx->setObjectName(QString::fromUtf8("horizontalLayout_turnx"));
        label_turnx = new QLabel(verticalLayoutWidget);
        label_turnx->setObjectName(QString::fromUtf8("label_turnx"));

        horizontalLayout_turnx->addWidget(label_turnx);

        doubleSpinBox_turnx = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_turnx->setObjectName(QString::fromUtf8("doubleSpinBox_turnx"));
        doubleSpinBox_turnx->setMinimum(-100.000000000000000);

        horizontalLayout_turnx->addWidget(doubleSpinBox_turnx);


        gridLayout_turn->addLayout(horizontalLayout_turnx, 0, 0, 1, 1);

        horizontalLayout_turnz = new QHBoxLayout();
        horizontalLayout_turnz->setObjectName(QString::fromUtf8("horizontalLayout_turnz"));
        label_turnz = new QLabel(verticalLayoutWidget);
        label_turnz->setObjectName(QString::fromUtf8("label_turnz"));

        horizontalLayout_turnz->addWidget(label_turnz);

        doubleSpinBox_turnz = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_turnz->setObjectName(QString::fromUtf8("doubleSpinBox_turnz"));
        doubleSpinBox_turnz->setMinimum(-100.000000000000000);

        horizontalLayout_turnz->addWidget(doubleSpinBox_turnz);


        gridLayout_turn->addLayout(horizontalLayout_turnz, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_turn);

        pushButton_turn = new QPushButton(verticalLayoutWidget);
        pushButton_turn->setObjectName(QString::fromUtf8("pushButton_turn"));

        verticalLayout->addWidget(pushButton_turn);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_move = new QLabel(verticalLayoutWidget);
        label_move->setObjectName(QString::fromUtf8("label_move"));
        label_move->setFont(font);

        verticalLayout->addWidget(label_move);

        gridLayout_move = new QGridLayout();
        gridLayout_move->setObjectName(QString::fromUtf8("gridLayout_move"));
        horizontalLayout_movez = new QHBoxLayout();
        horizontalLayout_movez->setObjectName(QString::fromUtf8("horizontalLayout_movez"));
        label_movez = new QLabel(verticalLayoutWidget);
        label_movez->setObjectName(QString::fromUtf8("label_movez"));

        horizontalLayout_movez->addWidget(label_movez);

        doubleSpinBox_movez = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_movez->setObjectName(QString::fromUtf8("doubleSpinBox_movez"));
        doubleSpinBox_movez->setMinimum(-100.000000000000000);

        horizontalLayout_movez->addWidget(doubleSpinBox_movez);


        gridLayout_move->addLayout(horizontalLayout_movez, 3, 0, 1, 1);

        horizontalLayout_movex = new QHBoxLayout();
        horizontalLayout_movex->setObjectName(QString::fromUtf8("horizontalLayout_movex"));
        label_movex = new QLabel(verticalLayoutWidget);
        label_movex->setObjectName(QString::fromUtf8("label_movex"));

        horizontalLayout_movex->addWidget(label_movex);

        doubleSpinBox_movex = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_movex->setObjectName(QString::fromUtf8("doubleSpinBox_movex"));
        doubleSpinBox_movex->setMinimum(-100.000000000000000);

        horizontalLayout_movex->addWidget(doubleSpinBox_movex);


        gridLayout_move->addLayout(horizontalLayout_movex, 0, 0, 1, 1);

        horizontalLayout_movey = new QHBoxLayout();
        horizontalLayout_movey->setObjectName(QString::fromUtf8("horizontalLayout_movey"));
        label_movey = new QLabel(verticalLayoutWidget);
        label_movey->setObjectName(QString::fromUtf8("label_movey"));

        horizontalLayout_movey->addWidget(label_movey);

        doubleSpinBox_movey = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_movey->setObjectName(QString::fromUtf8("doubleSpinBox_movey"));
        doubleSpinBox_movey->setMinimum(-100.000000000000000);

        horizontalLayout_movey->addWidget(doubleSpinBox_movey);


        gridLayout_move->addLayout(horizontalLayout_movey, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_move);

        pushButton_move = new QPushButton(verticalLayoutWidget);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));

        verticalLayout->addWidget(pushButton_move);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1251, 22));
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
        label_chname->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \321\204\320\260\320\271\320\273\320\260(1.txt, 2.txt, 3.txt, 4.txt)", nullptr));
        label_name->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        lineEdit_file->setText(QApplication::translate("MainWindow", "../lab_01/1.txt", nullptr));
        pushButton_name->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        label_scale->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\265\321\206\320\270\320\265\320\275\321\202\321\213 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_kx->setText(QApplication::translate("MainWindow", "kx", nullptr));
        label_ky->setText(QApplication::translate("MainWindow", "ky", nullptr));
        label_kz->setText(QApplication::translate("MainWindow", "kz", nullptr));
        pushButton_scale->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_turn->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_turny->setText(QApplication::translate("MainWindow", "alphaY", nullptr));
        label_turnx->setText(QApplication::translate("MainWindow", "alphaX", nullptr));
        label_turnz->setText(QApplication::translate("MainWindow", "alphaZ", nullptr));
        pushButton_turn->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_move->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_movez->setText(QApplication::translate("MainWindow", "dz", nullptr));
        label_movex->setText(QApplication::translate("MainWindow", "dx", nullptr));
        label_movey->setText(QApplication::translate("MainWindow", "dy", nullptr));
        pushButton_move->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
