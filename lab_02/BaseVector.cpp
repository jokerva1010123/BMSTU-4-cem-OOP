#include "BaseVector.h"

BaseVector::BaseVector()
{
    size = 0;
}

BaseVector::BaseVector(const size_t sizeValue)
{
    size = sizeValue;
}

BaseVector::~BaseVector()
{
    ;
}

bool BaseVector::IsEmpty()
{
    return size == 0;
}

size_t BaseVector::GetSize()
{
    return size;
}
