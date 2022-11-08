#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <iostream>
#include <iomanip>

// C++ APO - Proxy Pattern
class ISortSwap
{
public:
    void Swap(int *, int *);
};
class BaseSort
{
public:
    BaseSort();
    void Sort();
    void SetSwap(ISortSwap *baseSwap);
};
class BubbleSort : public BaseSort
{
public:
    void Sort();
};
#endif