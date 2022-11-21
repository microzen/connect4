/* ********************************************************
**                        Winning                        **  
** Determines the different possible ways a player could **
** win                                                   **
**********************************************************/

#include <iostream>
#include "../connect4.hpp"
using namespace std;

class WayOfWin
{
public:
    int compare(int index, int *array, int size)
    {
        // cout << "compare: ";
        // for (size_t i = 0; i < size; i++)
        // {
        //     cout << array[i] << " ";
        // }

        int range = 1;
        int left_value = next_left();
        int right_value = next_right();
        // cout << "index: " << this->_index << endl;
        // cout << "left:" << left_value << endl;
        // cout << "right: " << right_value << endl;

        bool isfind = false;
        do
        {
            isfind = false;
            for (size_t i = 0; i < size; i++)
            {
                if (array[i] == left_value)
                {
                    left_value = next_left();
                    range++;
                    isfind = true;
                }

                if (array[i] == right_value)
                {
                    right_value = next_right();
                    range++;
                    isfind = true;
                }
            }
        } while (isfind);
        return range;
    }
    int maxValue()
    {
        return _ways[_max_index];
    }
    int minValue()
    {
        return _ways[_min_index];
    }
    virtual void init() = 0;
    int size = 0;

protected:
    int _way_size = 7;
    int _ways[7];
    int _index = 0;
    int _min_index = 0;
    int _max_index = 6;

private:
    int _left_index = 0;
    int _right_index = 0;
    int next_left()
    {
        _left_index++;
        if (_index - _left_index < _min_index)
            return -1;
        return _ways[_index - _left_index];
    }
    int next_right()
    {
        _right_index++;
        if (_index + _left_index > _max_index)
            return -1;
        return _ways[_index + _right_index];
    }
};
class HorizontalOfWin : public WayOfWin
{
public:
    HorizontalOfWin(int step)
    {
        this->_step = step;
        this->init();
    }
    void init()
    {
        int row = this->_step / C4_COLUMN;
        int row_min = row * C4_COLUMN;
        int row_max = row_min + C4_COLUMN - 1;
        int column = this->_step - row_min;
        this->_index = column;
        for (int i = 0; i < this->_way_size; i++)
        {
            _ways[i] = row_min + i;
        }
    }

private:
    int _step = -1;
};
class VOfWin : public WayOfWin
{
public:
    VOfWin(int step)
    {
        this->_step = step;
        this->init();
    }
    void init()
    {
        int row = this->_step / C4_COLUMN;
        int row_min = row * C4_COLUMN;
        int row_max = row_min + C4_COLUMN - 1;
        int column = this->_step - row_min;

        this->_max_index = 5;
        for (size_t i = 0; i < this->_max_index + 1; i++)
        {
            _ways[i] = i * C4_COLUMN + column;
            if (this->_ways[i] == this->_step)
            {
                this->_index = i;
            }
        }
    }

private:
    int _step = -1;
};

class UOfWin : public WayOfWin
{
public:
    UOfWin(int step)
    {
        this->_step = step;
        this->init();
    }
    void init()
    {

        int row = this->_step / C4_COLUMN;
        int row_min = row * C4_COLUMN;
        int row_max = row_min + C4_COLUMN - 1;
        int column = this->_step - row_min;
        this->_way_size = 7;

        this->_index = column;
        this->_ways[this->_index] = this->_step;

        this->_max_index = this->_index;
        this->_min_index = this->_index;

        int temp = -1;
        for (size_t i = this->_index; i >= 0; i--)
        {

            temp = this->_ways[i] + 7;
            if (temp > 41)
            {
                break;
            }
            this->_ways[i - 1] = temp - 1;
            this->_min_index = i - 1;
        }
        for (size_t i = this->_index; i < this->_way_size; i++)
        {
            temp = this->_ways[i] - 7;
            if (temp < 0)
            {
                break;
            }
            this->_ways[i + 1] = temp + 1;
            this->_max_index = i + 1;
        }
    }

private:
    int _step = -1;
};

class DOfWin : public WayOfWin
{
public:
    DOfWin(int step)
    {
        this->_step = step;
        this->init();
    }
    void init()
    {

        int row = this->_step / C4_COLUMN;
        int row_min = row * C4_COLUMN;
        int row_max = row_min + C4_COLUMN - 1;
        int column = this->_step - row_min;
        this->_way_size = 7;

        this->_index = column;
        this->_ways[this->_index] = this->_step;

        this->_max_index = this->_index;
        this->_min_index = this->_index;

        int temp = -1;
        for (size_t i = this->_index; i > 0; i--)
        {
            temp = this->_ways[i] - 7;
            if (temp < 0)
            {
                break;
            }
            this->_ways[i - 1] = temp - 1;
            this->_min_index = i - 1;
        }
        for (size_t i = this->_index; i < this->_way_size; i++)
        {
            temp = this->_ways[i] + 7;
            if (temp > 41)
            {
                break;
            }
            this->_ways[i + 1] = temp + 1;
            this->_max_index = i + 1;
        }
    }

private:
    int _step = -1;
};

class C4Winning
{
private:
    int _step = -1;
    int _recording_size = 0;
    int *_recording = nullptr;
    int _orderly_index = -1;
    int *_orderly_list = nullptr;

    void orderListAndFindStepIndex()
    {
        _orderly_list = _recording;
        _recording = new int[_recording_size];
        _recording[_recording_size - 1] = _orderly_list[_recording_size - 1];

        int isChange = false;
        int temp = 0;
        for (int i = 1; i < _recording_size; i++)
        {
            isChange = false;
            for (int k = 0; k < _recording_size - i; k++)
            {
                if (i == 1)
                {
                    _recording[_recording_size] = _orderly_list[_recording_size];
                }
                if (_orderly_list[k] > _orderly_list[k + 1])
                {
                    if (_orderly_index == k + 1)
                    {
                        _orderly_index = k;
                    }
                    temp = _orderly_list[k];
                    _orderly_list[k] = _orderly_list[k + 1];
                    _orderly_list[k + 1] = temp;
                    isChange = true;
                }
            }
            if (isChange == false)
                break;
        }
    }

public:
    C4Winning(int *, int);
    bool isWin();
};

C4Winning::C4Winning(int *steps, int size)
{
    _recording_size = size;
    _recording = steps;
    _step = _recording[_recording_size - 1];
    this->orderListAndFindStepIndex();
}
bool C4Winning::isWin()
{
    WayOfWin *h = new HorizontalOfWin(this->_step);
    int h_size = 0;
    h_size = h->compare(this->_orderly_index, this->_orderly_list, this->_recording_size);
    if (h_size >= 4)
    {
        return true;
    }
    WayOfWin *v = new VOfWin(this->_step);
    h_size = v->compare(this->_orderly_index, this->_orderly_list, this->_recording_size);
    if (h_size >= 4)
    {
        return true;
    }
    WayOfWin *u = new UOfWin(this->_step);
    h_size = u->compare(this->_orderly_index, this->_orderly_list, this->_recording_size);
    if (h_size >= 4)
    {
        return true;
    }
    WayOfWin *d = new DOfWin(this->_step);
    h_size = d->compare(this->_orderly_index, this->_orderly_list, this->_recording_size);
    if (h_size >= 4)
    {
        return true;
    }
    // cout << "h_size:" << h_size << endl;
}
bool IC4BaseRule::isWin(int *steps, int size)
{
    C4Winning *win = new C4Winning(steps, size);
    return win->isWin();
}