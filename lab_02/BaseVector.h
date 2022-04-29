#ifndef BASEVECTOR_H
#define BASEVECTOR_H

#include<cstdlib>

class BaseVector
{
    public:
        BaseVector();
        BaseVector(const size_t sizeValue);
        ~BaseVector();

        bool IsEmpty();
        size_t GetSize();

    protected:
        size_t size = 0;
};

#endif // BASEVECTOR_H
