#ifndef CONNECT4_HPP
#define CONNECT4_HPP

#define C4_ROW 6
#define C4_COLUMN 7
#define C4_MAXVALUE 42

enum PieceColor
{
    NONE = 0,
    RED,
    YELLOW
};

int dropPiece(int, PieceColor, int **);
void dropPieceToIndex(int, PieceColor, int **);

#endif