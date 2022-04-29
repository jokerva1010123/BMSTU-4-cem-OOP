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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_spin;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox_spin_x;
    QDoubleSpinBox *doubleSpinBox_spin_y;
    QDoubleSpinBox *doubleSpinBox_spin_z;
    QPushButton *pushButton_spin;
    QGroupBox *groupBox_move;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *doubleSpinBox_move_x;
    QDoubleSpinBox *doubleSpinBox_move_y;
    QDoubleSpinBox *doubleSpinBox_move_z;
    QPushButton *pushButton_move;
    QGroupBox *groupBox_scale;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_6;
    QDoubleSpinBox *doubleSpinBox_scale_x;
    QDoubleSpinBox *doubleSpinBox_scale_y;
    QDoubleSpinBox *doubleSpinBox_scale_z;
    QPushButton *pushButton_scale;
    QPushButton *pushButton_load;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 672);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_spin = new QGroupBox(centralwidget);
        groupBox_spin->setObjectName(QString::fromUtf8("groupBox_spin"));
        groupBox_spin->setGeometry(QRect(810, 10, 281, 171));
        QFont font;
        font.setPointSize(16);
        groupBox_spin->setFont(font);
        layoutWidget = new QWidget(groupBox_spin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(-40, 30, 161, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        doubleSpinBox_spin_x = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_spin_x->setObjectName(QString::fromUtf8("doubleSpinBox_spin_x"));
        doubleSpinBox_spin_x->setFont(font1);

        verticalLayout->addWidget(doubleSpinBox_spin_x);

        doubleSpinBox_spin_y = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_spin_y->setObjectName(QString::fromUtf8("doubleSpinBox_spin_y"));
        doubleSpinBox_spin_y->setFont(font1);

        verticalLayout->addWidget(doubleSpinBox_spin_y);

        doubleSpinBox_spin_z = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_spin_z->setObjectName(QString::fromUtf8("doubleSpinBox_spin_z"));
        doubleSpinBox_spin_z->setFont(font1);

        verticalLayout->addWidget(doubleSpinBox_spin_z);


        horizontalLayout->addLayout(verticalLayout);

        pushButton_spin = new QPushButton(groupBox_spin);
        pushButton_spin->setObjectName(QString::fromUtf8("pushButton_spin"));
        pushButton_spin->setGeometry(QRect(150, 70, 101, 51));
        QFont font2;
        font2.setPointSize(12);
        pushButton_spin->setFont(font2);
        groupBox_move = new QGroupBox(centralwidget);
        groupBox_move->setObjectName(QString::fromUtf8("groupBox_move"));
        groupBox_move->setGeometry(QRect(810, 190, 281, 151));
        groupBox_move->setFont(font);
        layoutWidget1 = new QWidget(groupBox_move);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(-40, 30, 161, 109));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        doubleSpinBox_move_x = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_move_x->setObjectName(QString::fromUtf8("doubleSpinBox_move_x"));
        doubleSpinBox_move_x->setFont(font1);

        verticalLayout_4->addWidget(doubleSpinBox_move_x);

        doubleSpinBox_move_y = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_move_y->setObjectName(QString::fromUtf8("doubleSpinBox_move_y"));
        doubleSpinBox_move_y->setFont(font1);

        verticalLayout_4->addWidget(doubleSpinBox_move_y);

        doubleSpinBox_move_z = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_move_z->setObjectName(QString::fromUtf8("doubleSpinBox_move_z"));
        doubleSpinBox_move_z->setFont(font1);

        verticalLayout_4->addWidget(doubleSpinBox_move_z);


        horizontalLayout_2->addLayout(verticalLayout_4);

        pushButton_move = new QPushButton(groupBox_move);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));
        pushButton_move->setGeometry(QRect(150, 60, 101, 51));
        pushButton_move->setFont(font2);
        groupBox_scale = new QGroupBox(centralwidget);
        groupBox_scale->setObjectName(QString::fromUtf8("groupBox_scale"));
        groupBox_scale->setGeometry(QRect(810, 350, 281, 141));
        groupBox_scale->setFont(font);
        layoutWidget_2 = new QWidget(groupBox_scale);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(-40, 30, 161, 109));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label_9);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        doubleSpinBox_scale_x = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_scale_x->setObjectName(QString::fromUtf8("doubleSpinBox_scale_x"));
        doubleSpinBox_scale_x->setFont(font1);

        verticalLayout_6->addWidget(doubleSpinBox_scale_x);

        doubleSpinBox_scale_y = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_scale_y->setObjectName(QString::fromUtf8("doubleSpinBox_scale_y"));
        doubleSpinBox_scale_y->setFont(font1);

        verticalLayout_6->addWidget(doubleSpinBox_scale_y);

        doubleSpinBox_scale_z = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_scale_z->setObjectName(QString::fromUtf8("doubleSpinBox_scale_z"));
        doubleSpinBox_scale_z->setFont(font1);

        verticalLayout_6->addWidget(doubleSpinBox_scale_z);


        horizontalLayout_3->addLayout(verticalLayout_6);

        pushButton_scale = new QPushButton(groupBox_scale);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setGeometry(QRect(130, 60, 141, 51));
        pushButton_scale->setFont(font2);
        pushButton_load = new QPushButton(centralwidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        pushButton_load->setGeometry(QRect(870, 550, 161, 71));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 781, 611));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1100, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lab_01 (\320\246\320\262\320\265\321\202\320\272\320\276\320\262 \320\230.\320\220. \320\230\320\2437-43\320\221)", nullptr));
        groupBox_spin->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label->setText(QApplication::translate("MainWindow", "x\302\260 :", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "y\302\260 :", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "z\302\260 :", nullptr));
        pushButton_spin->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        groupBox_move->setTitle(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "dx:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "dy:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "dz:", nullptr));
        pushButton_move->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        groupBox_scale->setTitle(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "kx:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "ky:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "kz:", nullptr));
        pushButton_scale->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_load->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
