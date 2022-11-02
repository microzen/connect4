#include <iostream>
#include <iomanip>

// C++ APO - Proxy Pattern
class ISortSwap
{
public:
    virtual void Swap(int *, int *) = 0;
};
class SortSwap : public ISortSwap
{
public:
    void Swap(int *index1, int *index2)
    {
        int temp;
        temp = *index1;
        *index1 = *index2;
        *index2 = temp;
    }
};
class BaseSort
{
public:
    BaseSort()
    {
        this->_baseSwap = new SortSwap();
    }
    virtual void Sort() = 0;
    void SetSwap(ISortSwap *baseSwap)
    {
        this->_baseSwap = baseSwap;
    };

protected:
    ISortSwap *_baseSwap = nullptr;
};

/// @brief AOP - Proxy Pattern
class SortAspect : public BaseSort, public ISortSwap
{
public:
    SortAspect(BaseSort *baseSort, ISortSwap *baseSwap)
    {
        this->_base = baseSort;
        this->_baseSwap = baseSwap;
    }
    void Sort()
    {
        std::string name = typeid(*_base).name();
        name = name.substr(2, name.length() - 1);
        std::cout << "\n----- Start " << name << " -----\nOriginal:";

        _base->Sort();

        std::cout << "\n ----- End " << name << " -----\n";
    }
    void Swap(int *index1, int *index2)
    {
        counter++;
        this->_baseSwap->Swap(index1, index2);

        std::cout << "Swap : ";
    }
    void Display()
    {
        this->Display();
    }

private:
    int counter = 0;
    BaseSort *_base = nullptr;
    ISortSwap *_baseSwap = nullptr;
};

class BubbleSort : public BaseSort
{
private:
    const int size = 8;
    int array[8] = {10, 8, 3, 14, 9, 6, 7, 2};

public:
    void Sort()
    {
        int isChange = false;
        for (int i = 1; i < this->size; i++)
        {
            isChange = false;
            for (int k = 0; k < size - i; k++)
            {
                if (this->array[k] > this->array[k + 1])
                {
                    int *index1 = &this->array[k];
                    int *index2 = &this->array[k + 1];
                    // this->_baseSwap->Swap(index1, index2);
                    isChange = true;
                }
            }
            if (isChange == false)
                break;
        }
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << std::setw(5) << array[i];
        }
        std::cout << std::endl;
    }
};
class SelectionSort : public BaseSort
{
private:
    const int size = 8;
    int array[8] = {10, 8, 3, 14, 9, 6, 7, 2};

public:
    void Sort()
    {
        int smallIndex = 0;
        for (int i = 0; i < this->size - 1; i++)
        {
            smallIndex = i;
            for (int k = i + 1; k < size; k++)
            {
                if (array[smallIndex] > array[k])
                {
                    smallIndex = k;
                }
            }
            if (smallIndex != i)
            {

                int *index1 = &this->array[smallIndex];
                int *index2 = &this->array[i];
                this->_baseSwap->Swap(index1, index2);
            }
        }
    }
};

// int main(int argc, char const *argv[])
// {
//     ISortSwap *swap = new SortSwap();
//     BaseSort *bubbleSort = new BubbleSort();
//     // Proxy
//     BaseSort *proxyBubble = new SortAspect(bubbleSort, swap);
//     proxyBubble->Sort();

//     BaseSort *selectionSort = new SelectionSort();
//     BaseSort *proxySelection = new SortAspect(selectionSort, swap);
//     proxySelection->Sort();

//     return 0;
// }