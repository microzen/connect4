#include <iostream>
#include "./connect4.hpp"

class RecordingCore
{
public:
    /// @brief push
    /// @param step
    void addSpet(int step)
    {
        if (_index >= C4_MAXVALUE)
        {
            throw "Max";
        }
        _steps[++_index] = step;
    }
    /// @brief pop
    void removeSpet()
    {
        if (_index < 0)
        {
            throw "Min";
        }
        _index--;
    }
    int *toArray()
    {
        int *re = new int[this->_index + 1];
        for (size_t i = 0; i <= this->_index; i++)
        {
            re[i] = _steps[i];
        }
        return re;
    }
    int getSize()
    {
        return this->_index + 1;
    }

private:
    int _index = -1;
    int _steps[C4_MAXVALUE];
};