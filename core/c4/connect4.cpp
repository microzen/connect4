
#include "../connect4.hpp"

int dropPiece(int lineNumber, PieceColor color, int array[C4_ROW][C4_COLUMN])
{
    if (lineNumber > 6 || lineNumber < 0)
    {
        throw "Error";
    }
    int *loop = array[0];
    int i = C4_ROW - 1;
    for (; i >= 0; i--)
    {
        if (array[i][lineNumber] == NONE)
        {
            array[i][lineNumber]=color;
            break;
        }
    }
    int index = i * C4_COLUMN + lineNumber;
    return index;
}
void dropPieceToIndex(int index, PieceColor color, int array[C4_ROW][C4_COLUMN])
{
    int row = index / C4_COLUMN;
    int column = index - row * C4_COLUMN;
    array[row][column] = color;
}