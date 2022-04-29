/********************************************************************************
** Form generated from reading UI file 'mygraphicview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYGRAPHICVIEW_H
#define UI_MYGRAPHICVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyGraphicView
{
public:

    void setupUi(QWidget *MyGraphicView)
    {
        if (MyGraphicView->objectName().isEmpty())
            MyGraphicView->setObjectName(QString::fromUtf8("MyGraphicView"));
        MyGraphicView->resize(400, 300);

        retranslateUi(MyGraphicView);

        QMetaObject::connectSlotsByName(MyGraphicView);
    } // setupUi

    void retranslateUi(QWidget *MyGraphicView)
    {
        MyGraphicView->setWindowTitle(QApplication::translate("MyGraphicView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyGraphicView: public Ui_MyGraphicView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYGRAPHICVIEW_H
