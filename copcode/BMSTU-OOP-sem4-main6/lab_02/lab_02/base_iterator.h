#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

class BaseIterator
{
public:
    BaseIterator();
    explicit BaseIterator(const BaseIterator&);

    ~BaseIterator();
protected:
    int index = 0;
    int num_elem = 0;
};

#endif // BASE_ITERATOR_H
