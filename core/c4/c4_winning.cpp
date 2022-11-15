#include <iostream>
#include "../connect4.hpp"
class WayOfWin
{
public:
    int compare(int index, int *array, int size)
    {
        int left_value = next_left();
        int right_value = next_right();
        int left_index = index - 1;
        int right_index = index + 1;

        int range = 0;

        while (left_index >= 0)
        {
            if (array[left_index] == left_value)
            {
                range++;
                left_value = next_left();
            }
            else
            {
                left_index--;
            }
        }

        while (right_index < size)
        {
            if (array[right_index] == right_value)
            {
                range++;
                right_value = next_right();
            }
            else
            {
                right_index++;
            }
        }
        return range;
    }
    int maxValue()
    {
        return ways[_max_index];
    }
    int minValue()
    {
        return ways[_min_index];
    }
    virtual void init() = 0;
    int size = 0;

protected:
    const int way_size = 7;
    int ways[7];
    int index = 0;
    int _min_index = 0;
    int _max_index = 0;

private:
    int _left_index = 0;
    int _right_index = 0;
    int next_left()
    {
        _left_index++;
        if (_left_index < _min_index)
            return -1;
        return ways[index - _left_index];
    }
    int next_right()
    {
        _right_index++;
        if (_right_index > _max_index)
            return -1;
        return ways[index + _right_index];
    }
};
class RowOfWin :public WayOfWin
{
public:
    RowOfWin(int step)
    {
        this->_step = step;
        this->init();
    }
    void init()
    {
        int row = this->_step / C4_COLUMN;
        int row_min = row * C4_COLUMN;
        int row_max = row_min + C4_COLUMN;
        int column = row - row_min;

        this->index = column;
        this->ways[this->index] = this->_step;

        for (size_t i = row + 1; i <= row_max && i <= row + 3; i++)
        {
            this->ways[i - row_min] = i;
            this->_min_index = i - row_min;
        }
        for (size_t i = row - 1; i >= row_min && i >= row - 3; i--)
        {
            this->ways[i - row_min] = i;
            this->_max_index = i - row_min;
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

    bool compare_row_win()
    {
        int row = this->_step / C4_COLUMN;
        int row_min = row * C4_COLUMN;
        int row_max = row_min + C4_COLUMN;

        int range = 1;

        int left_cursor = 0;
        int right_cursor = 0;
        bool left_loop = true;
        bool right_loop = true;
        int next_left_array = -1;
        int next_right_array = -1;
        int next_left_step = -1;
        int next_right_step = -1;

        do
        {
            next_left_array = this->_orderly_list[this->_orderly_index - (left_cursor + 1)];
            next_right_array = this->_orderly_list[this->_orderly_index + (right_cursor + 1)];

            next_left_step = this->_step - (left_cursor + 1);
            next_right_step = this->_step + (right_cursor + 1);

            if (left_cursor + right_cursor >= 3)
            {
                return true;
            }
            else if (left_loop == false && right_loop == false)
            {
                return false;
            }
            if (left_loop)
            {
                if (next_left_array >= row_min && next_left_array == next_left_step)
                {
                    left_cursor++;
                }
                else
                {
                    left_loop = false;
                }
            }
            if (right_loop)
            {
                if (next_right_array <= row_max && next_right_array == next_right_step)
                {
                    right_cursor++;
                }
                else
                {
                    right_loop = false;
                }
            }

        } while (1);
    }
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
    C4Winning();
    bool isWin();
    // ~C4Winning();
};

C4Winning::C4Winning()
{
    _recording_size = 10;
    int r[] = {41, 40, 35, 31, 29, 30, 37, 21, 22, 38};
    _recording = r;
    _step = _recording[_recording_size - 1];
}
bool IC4BaseRule::isWin(int* steps, int size)
{
    // rw->compare()
    return 0;
}