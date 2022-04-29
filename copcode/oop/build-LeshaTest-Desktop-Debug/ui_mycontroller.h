/********************************************************************************
** Form generated from reading UI file 'mycontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCONTROLLER_H
#define UI_MYCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyController
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *rot_xEdit;
    QLineEdit *rot_yEdit;
    QLineEdit *rot_zEdit;
    QLabel *label_4;
    QPushButton *rotateButton;
    QGroupBox *groupBox_2;
    QLineEdit *kxEdit;
    QPushButton *scaleButton;
    QLabel *label_12;
    QLabel *label_6;
    QLabel *label_14;
    QLineEdit *dzEdit;
    QLabel *label_15;
    QLineEdit *dxEdit;
    QLineEdit *dyEdit;
    QPushButton *moveButton;
    QPushButton *fileButton;

    void setupUi(QWidget *MyController)
    {
        if (MyController->objectName().isEmpty())
            MyController->setObjectName(QString::fromUtf8("MyController"));
        MyController->resize(253, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyController->sizePolicy().hasHeightForWidth());
        MyController->setSizePolicy(sizePolicy);
        MyController->setMinimumSize(QSize(200, 400));
        verticalLayoutWidget = new QWidget(MyController);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 251, 381));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font;
        font.setPointSize(10);
        groupBox->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(67, 30, 41, 21));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(67, 60, 41, 21));
        label_3->setFont(font1);
        rot_xEdit = new QLineEdit(groupBox);
        rot_xEdit->setObjectName(QString::fromUtf8("rot_xEdit"));
        rot_xEdit->setGeometry(QRect(112, 30, 51, 21));
        rot_yEdit = new QLineEdit(groupBox);
        rot_yEdit->setObjectName(QString::fromUtf8("rot_yEdit"));
        rot_yEdit->setGeometry(QRect(112, 60, 51, 21));
        rot_zEdit = new QLineEdit(groupBox);
        rot_zEdit->setObjectName(QString::fromUtf8("rot_zEdit"));
        rot_zEdit->setGeometry(QRect(112, 90, 51, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(67, 90, 41, 21));
        label_4->setFont(font1);
        rotateButton = new QPushButton(groupBox);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
        rotateButton->setGeometry(QRect(86, 121, 81, 23));

        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(verticalLayoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 160));
        groupBox_2->setFont(font);
        kxEdit = new QLineEdit(groupBox_2);
        kxEdit->setObjectName(QString::fromUtf8("kxEdit"));
        kxEdit->setGeometry(QRect(50, 30, 61, 21));
        scaleButton = new QPushButton(groupBox_2);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setGeometry(QRect(0, 120, 121, 23));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 30, 41, 21));
        label_12->setFont(font1);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(130, 90, 41, 21));
        label_6->setFont(font1);
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(130, 30, 41, 21));
        label_14->setFont(font1);
        dzEdit = new QLineEdit(groupBox_2);
        dzEdit->setObjectName(QString::fromUtf8("dzEdit"));
        dzEdit->setGeometry(QRect(170, 90, 61, 21));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(130, 60, 41, 21));
        label_15->setFont(font1);
        dxEdit = new QLineEdit(groupBox_2);
        dxEdit->setObjectName(QString::fromUtf8("dxEdit"));
        dxEdit->setGeometry(QRect(170, 30, 61, 21));
        dyEdit = new QLineEdit(groupBox_2);
        dyEdit->setObjectName(QString::fromUtf8("dyEdit"));
        dyEdit->setGeometry(QRect(170, 60, 61, 21));
        moveButton = new QPushButton(groupBox_2);
        moveButton->setObjectName(QString::fromUtf8("moveButton"));
        moveButton->setGeometry(QRect(130, 120, 101, 23));

        verticalLayout_2->addWidget(groupBox_2);

        fileButton = new QPushButton(verticalLayoutWidget);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));

        verticalLayout_2->addWidget(fileButton);


        retranslateUi(MyController);

        QMetaObject::connectSlotsByName(MyController);
    } // setupUi

    void retranslateUi(QWidget *MyController)
    {
        MyController->setWindowTitle(QApplication::translate("MyController", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("MyController", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        label_2->setText(QApplication::translate("MyController", "\321\205", nullptr));
        label_3->setText(QApplication::translate("MyController", "y", nullptr));
        rot_xEdit->setText(QApplication::translate("MyController", "0", nullptr));
        rot_yEdit->setText(QApplication::translate("MyController", "0", nullptr));
        rot_zEdit->setText(QApplication::translate("MyController", "0", nullptr));
        label_4->setText(QApplication::translate("MyController", "z", nullptr));
        rotateButton->setText(QApplication::translate("MyController", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        groupBox_2->setTitle(QApplication::translate("MyController", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265        \320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        kxEdit->setText(QApplication::translate("MyController", "0", nullptr));
        scaleButton->setText(QApplication::translate("MyController", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_12->setText(QApplication::translate("MyController", "k = ", nullptr));
        label_6->setText(QApplication::translate("MyController", "dz = ", nullptr));
        label_14->setText(QApplication::translate("MyController", "dx = ", nullptr));
        dzEdit->setText(QApplication::translate("MyController", "0", nullptr));
        label_15->setText(QApplication::translate("MyController", "dy = ", nullptr));
        dxEdit->setText(QApplication::translate("MyController", "0", nullptr));
        dyEdit->setText(QApplication::translate("MyController", "0", nullptr));
        moveButton->setText(QApplication::translate("MyController", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        fileButton->setText(QApplication::translate("MyController", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyController: public Ui_MyController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCONTROLLER_H
