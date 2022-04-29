#pragma once
#include <QString>

class BaseExeption
{
public:
    BaseExeption() {}
    virtual QString ErrorMsg() = 0;
};

class MemoryAllocation: public BaseExeption
{
public:
    MemoryAllocation() {}
    QString ErrorMsg() { return QString("Memory allocation error"); }
};

class OutOfBounds: public BaseExeption
{
public:
    OutOfBounds() {}
    QString ErrorMsg() { return QString("Out of bounds error"); }
};

class UnknownCondition: public BaseExeption
{
public:
    UnknownCondition() {}
    QString ErrorMsg() { return QString("Out of bounds error"); }
};
