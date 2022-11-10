#include <iostream>
#include "./connect4.hpp"

void C4Recording::addStep(int step)
{
    if (_index >= C4_MAXVALUE)
    {
        throw "Max";
    }
    _steps[++_index] = step;
}
/// @brief pop
void C4Recording::removeStep()
{
    if (_index < 0)
    {
        throw "Min";
    }
    _index--;
}
int *C4Recording::toArray()
{
    int *re = new int[this->_index + 1];
    for (size_t i = 0; i <= this->_index; i++)
    {
        re[i] = _steps[i];
    }
    return re;
}
int C4Recording::getSize()
{
    return this->_index + 1;
}