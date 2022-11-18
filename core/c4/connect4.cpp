
#include "../connect4.hpp"

namespace std
{
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
                array[i][lineNumber] = color;
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
}

int IC4::dropPiece(int line, PieceColor color)
{
    std::dropPiece(line, color, this->_table);
}
void IC4::getBoard(int newTable[C4_ROW][C4_COLUMN])
{
    for (int i=0; i < 7; i++)
      *newTable[i] = *_table[i];
}

void IC4::init()
{
    for (int c = 0; c < C4_COLUMN; c++)
    for (int r = 0; r < C4_ROW; r++)
       _table[r][c] = 0;
}
IC4::IC4(){
    
}