#include "button.h"
#include "qdebug.h"

Button::Button(QWidget *parent)
    : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()),
                     this, SLOT(press()));
    QObject::connect(this, SIGNAL(unpress_signal()),
                     this, SLOT(unpress()));

    this->current_state = NOTACTIVE;
    this->current_button_floor = 1;
}

void Button::set_floor(const int &floor)
{
    this->current_button_floor = floor;
}

void Button::press()
{
    if (current_state != NOTACTIVE)
    {
        return;
    }

    this->setStyleSheet("background-color:yellow;");
    this->update();

    qDebug() <<  "ВЫЗОВ ЭТАЖ № " << this->current_button_floor;
    this->current_state = ACTIVE;
    this->setDisabled(true);

    emit press_signal(this->current_button_floor);
}

void Button::unpress()
{
    if (current_state != ACTIVE)
    {
        return;
    }

    this->setStyleSheet("background-color:pink;");
    this->update();

    this->current_state = NOTACTIVE;
    this->setDisabled(false);
}

