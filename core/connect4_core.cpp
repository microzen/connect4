
#include "../connect4/connect4.hpp"

int dropPiece(int lineNumber, PieceColor color, int **array)
{
    if (lineNumber > 7 || lineNumber < 1)
    {
        throw "Error";
    }
    int *loop = array[0];
    int index = (C4_ROW - 1) * C4_COLUMN + lineNumber;
    for (int i = C4_ROW - 1; i >= 0; i--)
    {
        if ((loop + i)[lineNumber] == NONE)
        {
            index = i * C4_ROW + lineNumber;
            (loop + i)[lineNumber] = color;
            break;
        }
    }
    return index;
}