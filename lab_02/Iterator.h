#ifndef class_Iter_h
#define class_Iter_h

#include "BaseIter.h"

template<class Type>
class Vector;

template<typename Type>
class Iterator : public BaseIter
{
    public:
        //конструкторы
        Iterator(const Iterator<Type>& iter);
        Iterator(const Vector<Type>& vec);

        Type& operator*();
        Type* operator->();
        operator bool() const;

        Iterator<Type>& operator=(const Iterator<Type>& iter);

        Iterator<Type>& operator+=(int n);
        Iterator<Type> operator+(int n) const;
        Iterator<Type>& operator++();
        Iterator<Type> operator++(int);

        Iterator<Type>& operator-=(int n);
        Iterator<Type> operator-(int n) const;
        Iterator<Type>& operator--();
        Iterator<Type> operator--(int);

        bool operator<=(const Iterator<Type>& b) const;
        bool operator<(const Iterator<Type>& b) const;
        bool operator>=(const Iterator<Type>& b) const;
        bool operator>(const Iterator<Type>& b) const;
        bool operator==(const Iterator<Type>& b) const;
        bool operator!=(const Iterator<Type>& b) const;

        bool check(int line) const;

    private:
        std::weak_ptr<Type[]> ptr;

    protected:
        Type* get_cur_ptr() const;
};

template<class Type>
Type* Iterator<Type>::get_cur_ptr() const
{
    std::shared_ptr<Type[]> copy_ptr = ptr.lock();
    //
    return copy_ptr.get() + index;
}

template<class Type>
Iterator<Type>::Iterator(const Vector<Type>& vec)
{
    index = 0;
    num_elem = vec.num_elem;
    ptr = vec.data_list;
    index = 0;
}

template<class Type>
Iterator<Type>::Iterator(const Iterator<Type>& iter)
{
    ptr = iter.ptr;
    index = iter.index;
    num_elem = iter.num_elem;
}

template<class Type>
Type& Iterator<Type>::operator*()
{
    check(__LINE__);

    std::shared_ptr<Type[]> copy_ptr = ptr.lock();
    return *get_cur_ptr();
}

template<class Type>
Type* Iterator<Type>::operator->()
{
    check(__LINE__);

    return get_cur_ptr();
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter)
{
    check(__LINE__);
    ptr = iter.ptr;
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator+=(int n)
{
    check(__LINE__);
    ptr += n;

    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator+(int n) const
{
    check(__LINE__);
    Iterator<Type> iter(*this);
    iter += n;

    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    check(__LINE__);
    ++(*this);

    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    check(__LINE__);
    ++index;

    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator-=(int n)
{
    check(__LINE__);
    index -= n;

    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator-(int n) const
{
    check(__LINE__);

    Iterator<Type> iter(*this);
    iter -= n;

    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    check(__LINE__);
    --(*this);

    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    check(__LINE__);
    --index;

    return *this;
}

template<class Type>
bool Iterator<Type>::operator<=(const Iterator<Type>& b) const
{
    check(__LINE__);

    return ptr <= b.ptr;
}

template<class Type>
bool Iterator<Type>::operator<(const Iterator<Type>& b) const
{
    check(__LINE__);

    return ptr < b.ptr;
}

template<class Type>
bool Iterator<Type>::operator>=(const Iterator<Type>& b) const
{
    check(__LINE__);

    return ptr >= b.ptr;
}

template<class Type>
bool Iterator<Type>::operator>(const Iterator<Type>& b) const
{
    check(__LINE__);

    return ptr > b.ptr;
}

template<class Type>
bool Iterator<Type>::operator==(const Iterator<Type>& b) const
{
    check(__LINE__);

    return ptr == b.ptr;
}

template<class Type>
bool Iterator<Type>::operator!=(const Iterator<Type>& b) const
{
    check(__LINE__);

    return ptr != b.ptr;
}

template<class Type>
Iterator<Type>::operator bool() const
{
    check(__LINE__);

    if (index >= num_elem || index < 0 || (num_elem == 0))
        return false;
    else
        return true;
}

template<class Type>
bool Iterator<Type>::check(int line) const
{
    if (!ptr.expired())
        return true;

    time_t t_time = time(NULL);
    throw deletedObj(__FILE__, typeid(*this).name(), line, ctime(&t_time));
    return false;
}

#endif /* class_Iter_h */
