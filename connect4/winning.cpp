// #include <iostream>
// #include "winning.hpp"
// #include "../core/connect4.hpp"
// #include "../common/sort.hpp"

// void log(std::string str);
// const int _WINNING_ARRAYS[69][4] = {
//     {0, 1, 2, 3},
//     {41, 40, 39, 38},
//     {7, 8, 9, 10},
//     {34, 33, 32, 31},
//     {14, 15, 16, 17},
//     {27, 26, 25, 24},
//     {21, 22, 23, 24},
//     {20, 19, 18, 17},
//     {28, 29, 30, 31},
//     {13, 12, 11, 10},
//     {35, 36, 37, 38},
//     {6, 5, 4, 3},
//     {0, 7, 14, 21},
//     {41, 34, 27, 20},
//     {1, 8, 15, 22},
//     {40, 33, 26, 19},
//     {2, 9, 16, 23},
//     {39, 32, 25, 18},
//     {3, 10, 17, 24},
//     {38, 31, 24, 17},
//     {4, 11, 18, 25},
//     {37, 30, 23, 16},
//     {5, 12, 19, 26},
//     {36, 29, 22, 15},
//     {6, 13, 20, 27},
//     {35, 28, 21, 14},
//     {0, 8, 16, 24},
//     {41, 33, 25, 17},
//     {7, 15, 23, 31},
//     {34, 26, 18, 10},
//     {14, 22, 30, 38},
//     {27, 19, 11, 3},
//     {35, 29, 23, 17},
//     {6, 12, 18, 24},
//     {28, 22, 16, 10},
//     {13, 19, 25, 31},
//     {21, 15, 9, 3},
//     {20, 26, 32, 38},
//     {36, 30, 24, 18},
//     {5, 11, 17, 23},
//     {37, 31, 25, 19},
//     {4, 10, 16, 22},
//     {2, 10, 18, 26},
//     {39, 31, 23, 15},
//     {1, 9, 17, 25},
//     {40, 32, 24, 16},
//     {9, 17, 25, 33},
//     {8, 16, 24, 32},
//     {11, 17, 23, 29},
//     {12, 18, 24, 30},
//     {1, 2, 3, 4},
//     {5, 4, 3, 2},
//     {8, 9, 10, 11},
//     {12, 11, 10, 9},
//     {15, 16, 17, 18},
//     {19, 18, 17, 16},
//     {22, 23, 24, 25},
//     {26, 25, 24, 23},
//     {29, 30, 31, 32},
//     {33, 32, 31, 30},
//     {36, 37, 38, 39},
//     {40, 39, 38, 37},
//     {7, 14, 21, 28},
//     {8, 15, 22, 29},
//     {9, 16, 23, 30},
//     {10, 17, 24, 31},
//     {11, 18, 25, 32},
//     {12, 19, 26, 33},
//     {13, 20, 27, 34},
// };
// void display(int *[4], int);
// // 0   1   2   3   4   5   6
// // 7   8   9  10  11  12  13
// // 14  15  16  17  18  19  20
// // 21  22  23  24  25  26  27
// // 28  29  30  31  32  33  34
// // 35  36  37  38  39  40  41

// // 0               -N-
// // 1 7             -N-
// // 2 8 14          -N-
// // 3 9 15 21               -N-
// // 4 10 16 22 28           -N-
// // 5 11 17 23 29 35                -N-
// // 6 12 18 24 30 36                -M-
// // 13 19 25 31 37          -M-
// // 20 26 32 38             -M-
// // 27 33 39                -M-
// // 34 40           -M-
// // 41

// // 0               -N-
// // 1 2             -N-
// // 3 4 5           -N-
// // 6 7 8 9                 -N-
// // 10 11 12 13 14          -N-
// // 15 16 17 18 19 20               -N-
// // 21 22 23 24 25 26               -M-
// // 27 28 29 30 31          -M-
// // 32 33 34 35             -M-
// // 36 37 38                -M-
// // 39 40           -M-
// // 41

// int **currentWin(int spet)
// {
// }
// int **wayOfWins()
// {

//     int winTree[42];
//     int number = 0;
//     int testNumber = 22;
//     int count = 0;
//     while (testNumber >= 7 || (testNumber + 1) % 7 == 0)
//     {
//         testNumber = testNumber - 7 + 1;
//         count++;
//     }

//     std::cout << testNumber << " Number\n";
//     std::cout << count << " Count\n";
//     if (testNumber < 7)
//     {
//         for (size_t i = 1; i <= testNumber; i++)
//         {
//             number += i;
//         }
//     }
//     else
//     {
//         number = C4_ROW + testNumber / C4_COLUMN;
//     }

//     std::cout << number + count << " Index\n";

//     return NULL;
//     for (size_t i = 0; i < C4_COLUMN * C4_ROW; i++)
//     {
//         winTree[i] = number;
//         std::cout << i << " ";
//         if (number % C4_COLUMN == 0)
//         {
//             std::cout << "\t\t-N-\n";
//             number = number / C4_COLUMN + 1;
//         }
//         else if (number + C4_COLUMN > C4_COLUMN * C4_ROW)
//         {
//             std::cout << "\t\t-M-\n";
//             number = C4_ROW + (number % C4_COLUMN) * 7;
//         }
//         else
//         {
//             number = number + C4_COLUMN - 1;
//         }
//     }
//     return NULL;

//     int range = 4;
//     int rowWinSum = C4_COLUMN - 3;
//     int *rowWin[4];
//     int size = 0;
//     for (size_t cindex = 0; cindex < C4_COLUMN - range; cindex++, size++)
//     {
//         for (int irange = 0; irange < range; irange++)
//         {

//             // *(rowWin[irange]) = cindex + irange;
//             std::cout << cindex + irange << " ";
//         }
//         // std::cout << rowWin[0] << " ";
//     }

//     return NULL;
// }

// int sortAndFindStepIndex(int *array, int size)
// {
//     int index = size - 1;
//     int isChange = false;
//     int temp = 0;
//     for (int i = 1; i < size; i++)
//     {
//         isChange = false;
//         for (int k = 0; k < size - i; k++)
//         {
//             if (array[k] > array[k + 1])
//             {
//                 if (index == k + 1)
//                 {
//                     index = k;
//                 }
//                 temp = array[k];
//                 array[k] = array[k + 1];
//                 array[k + 1] = temp;
//                 isChange = true;
//             }
//         }
//         if (isChange == false)
//             break;
//     }
//     return index;
// }

// bool rowWin(int step, int *array, int size, int index)
// {
//     int row, rowWinMin, rowWinMax;
//     row = step / C4_COLUMN;
//     rowWinMin = row * C4_COLUMN;
//     rowWinMax = rowWinMin + C4_COLUMN;

//     int left_cursor = 0;
//     int right_cursor = 0;
//     bool left_loop = true;
//     bool right_loop = true;
//     int next_left_array = -1;
//     int next_right_array = -1;
//     int next_left_step = -1;
//     int next_right_step = -1;
//     int test = 0;
//     do
//     {
//         test++;
//         next_left_array = array[index - (left_cursor + 1)];
//         next_right_array = array[index + (right_cursor + 1)];

//         next_left_step = step - (left_cursor + 1);
//         next_right_step = step + (right_cursor + 1);

//         if (left_cursor + right_cursor >= 3)
//         {
//             return true;
//         }
//         else if (left_loop == false && right_loop == false)
//         {
//             return false;
//         }
//         if (left_loop)
//         {
//             if (next_left_array >= rowWinMin && next_left_array == next_left_step)
//             {
//                 log("left array" + std::to_string(next_left_array));
//                 log("left step" + std::to_string(next_left_step));
//                 left_cursor++;
//             }
//             else
//             {
//                 left_loop = false;
//                 log("----");
//             }
//         }
//         if (right_loop)
//         {
//             if (next_right_array <= rowWinMax && next_right_array == next_right_step)
//             {
//                 log("right array" + std::to_string(next_right_array));
//                 log("right step" + std::to_string(next_right_step));
//                 right_cursor++;
//             }
//             else
//             {
//                 right_loop = false;
//                 log("****");
//             }
//         }

//     } while (1);
// }
// int binarySearch(int value, int *array, int size)
// {
//     int left = 0, right = size - 1;
//     int mid_number = 0;
//     do
//     {
//         mid_number = (left + right) / 2;
//         if (array[mid_number] == value)
//             return mid_number;
//         else if (array[mid_number] > value)
//             left = mid_number;
//         else
//             right = mid_number;

//     } while (left <= right);
//     return -1;
// }
// void display(int *array, int size)
// {
//     for (size_t i = 0; i < size; i++)
//     {
//         std::cout << array[i] << " ";
//     }
//     std::cout << std::endl;
// }
// void log(std::string str)
// {
//     std::cout << str << std::endl;
// }

// bool isWin(int *playerRecording, int size)
// {
//     std::cout << "Start ";

//     if (size < 4)
//         return false;
//     int step = playerRecording[size - 1];
//     int index = -1;
//     index = sortAndFindStepIndex(playerRecording, size);

//     std::cout << "step: " << step << std::endl;
//     std::cout << "index: " << index << std::endl;
//     display(playerRecording, size);

//     bool iswin = rowWin(step, playerRecording, size, index);
//     std::cout << "isWin: " << iswin << std::endl;
//     return false;
// }

// // int main()
// // {
// //   int size = 10;
// //   int array[] = {41, 40, 35, 36, 29, 30, 37, 21, 22, 38};
// //   isWin(array, size);
// //   return 0;
// // }