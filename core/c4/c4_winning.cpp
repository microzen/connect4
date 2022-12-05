/* ********************************************************
**                        Winning                        **
** Determines the different possible ways a player could **
** win                                                   **

// MIT Licence
// Copyright (c) 2020 Ania Kubow

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

**********************************************************/

#include "../connect4.hpp"
#include <iostream>
#include <memory>
using namespace std;

class WayOfWin
{
public:
  int compare(int index, int *array, int size)
  {
    cout << "Compare: ";
    for (size_t i = 0; i < size; i++)
    {
      cout << array[i] << ", ";
    }
    cout << "\n";
    int range = 1;
    int left_value = next_left();
    int right_value = next_right();

    cout << "index: " << this->_index << endl;
    cout << "left:" << left_value << endl;
    cout << "right: " << right_value << endl;

    cout << "min index: " << this->_min_index << endl;
    cout << "max index: " << this->_max_index << endl;

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
    cout << "Compared!!" << endl;
    return range;
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

    cout << "H Init() " << endl;
    int row = this->_step / C4_COLUMN;
    int row_min = row * C4_COLUMN;
    int row_max = row_min + C4_COLUMN - 1;
    int column = this->_step - row_min;
    this->_index = column;
    for (int i = 0; i < this->_way_size; i++)
    {
      _ways[i] = row_min + i;
    }
    cout << "H Winning: ";
    for (size_t i = 0; i < this->_way_size; i++)
    {
      cout << this->_ways[i] << ", ";
    }
    cout << "\n";
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
    cout << "V Init() " << endl;
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
    cout << "V Winning: ";
    for (size_t i = 0; i < this->_way_size; i++)
    {
      cout << this->_ways[i] << ", ";
    }
    cout << "\n";
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

    cout << "U Init() " << endl;
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
    cout << "U Winning: ";
    for (size_t i = 0; i < this->_way_size; i++)
    {
      cout << this->_ways[i] << ", ";
    }
    cout << "\n";
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

    cout << "D Init() " << endl;
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
    cout << "D Winning: ";
    for (size_t i = 0; i < this->_way_size; i++)
    {
      cout << this->_ways[i] << ", ";
    }
    cout << "\n";
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
  // auto *h = new HorizontalOfWin(this->_step);
  // auto *v = new VOfWin(this->_step);
  // auto *u = new UOfWin(this->_step);
  // auto *d = new DOfWin(this->_step);

  // int h_size = 0;

  // h_size = h->compare(this->_orderly_index, this->_orderly_list,
  //                     this->_recording_size);
  // if (h_size >= 4)
  // {
  //   return true;
  // }
  // h_size = v->compare(this->_orderly_index, this->_orderly_list,
  // this->_recording_size); if (h_size >= 4)
  // {
  //     return true;
  // }
  // h_size = u->compare(this->_orderly_index, this->_orderly_list,
  // this->_recording_size); if (h_size >= 4)
  // {
  //     return true;
  // }
  // h_size = d->compare(this->_orderly_index, this->_orderly_list,
  // this->_recording_size); if (h_size >= 4)
  // {
  //     return true;
  // }
  return false;
  // cout << "h_size:" << h_size << endl;
}
bool IC4BaseRule::isWin(int *steps, int size)
{
  if (size < 3)
  {
    return false;
  }
  const int _WINNING_ARRAYS[69][4] = {
      {0, 1, 2, 3},
      {41, 40, 39, 38},
      {7, 8, 9, 10},
      {34, 33, 32, 31},
      {14, 15, 16, 17},
      {27, 26, 25, 24},
      {21, 22, 23, 24},
      {20, 19, 18, 17},
      {28, 29, 30, 31},
      {13, 12, 11, 10},
      {35, 36, 37, 38},
      {6, 5, 4, 3},
      {0, 7, 14, 21},
      {41, 34, 27, 20},
      {1, 8, 15, 22},
      {40, 33, 26, 19},
      {2, 9, 16, 23},
      {39, 32, 25, 18},
      {3, 10, 17, 24},
      {38, 31, 24, 17},
      {4, 11, 18, 25},
      {37, 30, 23, 16},
      {5, 12, 19, 26},
      {36, 29, 22, 15},
      {6, 13, 20, 27},
      {35, 28, 21, 14},
      {0, 8, 16, 24},
      {41, 33, 25, 17},
      {7, 15, 23, 31},
      {34, 26, 18, 10},
      {14, 22, 30, 38},
      {27, 19, 11, 3},
      {35, 29, 23, 17},
      {6, 12, 18, 24},
      {28, 22, 16, 10},
      {13, 19, 25, 31},
      {21, 15, 9, 3},
      {20, 26, 32, 38},
      {36, 30, 24, 18},
      {5, 11, 17, 23},
      {37, 31, 25, 19},
      {4, 10, 16, 22},
      {2, 10, 18, 26},
      {39, 31, 23, 15},
      {1, 9, 17, 25},
      {40, 32, 24, 16},
      {9, 17, 25, 33},
      {8, 16, 24, 32},
      {11, 17, 23, 29},
      {12, 18, 24, 30},
      {1, 2, 3, 4},
      {5, 4, 3, 2},
      {8, 9, 10, 11},
      {12, 11, 10, 9},
      {15, 16, 17, 18},
      {19, 18, 17, 16},
      {22, 23, 24, 25},
      {26, 25, 24, 23},
      {29, 30, 31, 32},
      {33, 32, 31, 30},
      {36, 37, 38, 39},
      {40, 39, 38, 37},
      {7, 14, 21, 28},
      {8, 15, 22, 29},
      {9, 16, 23, 30},
      {10, 17, 24, 31},
      {11, 18, 25, 32},
      {12, 19, 26, 33},
      {13, 20, 27, 34},
  };
  int r = 0;
  for (int i = 0; i < 69; i++)
  {
    r = 0;
    for (int k = 0; k < 4; k++)
    {
      for (int h = 0; h < size; h++)
      {
        if (steps[h] == _WINNING_ARRAYS[i][k])
        {
          r++;
          break;
        }
      }
    }
    if (r >= 4)
    {
      return true;
    }
  }
  return false;
}