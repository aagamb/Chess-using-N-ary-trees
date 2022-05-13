#ifndef PIECES_H_INCLUDED
#define PIECES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "possibleMoves.h"
#include <string.h>

typedef struct node{
    char type;
    char color;
    float points;
    int x;
    int y;
}node;

typedef node*** board;

board initB();
void printB(board b);
char makeSquareEmpty(board* b, int oldX, int oldY, int newX, int newY);
void changeNewSquare(board* b, int oldX, int oldY, int newX, int newY, char type);
void movePiece(board* b, int oldX, int oldY, int newX, int newY);

int** allRookMoves(board b, int currX, int currY);
int** allKnightMoves(board b, int oldX, int oldY);
int** allBishopMoves(board b, int oldX, int oldY);
int** allQueenMoves(board b, int oldX, int oldY);
int** allPawnMoves(board b, int oldX, int oldY);

int** validMoves(board b, int oldX, int oldY);



//helpers
int isCoordInBoard(int x, int y);


#endif


