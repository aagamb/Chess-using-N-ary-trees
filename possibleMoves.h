#ifndef POSSIBLEMOVES_H_INCLUDED
#define POSSIBLEMOVES_H_INCLUDED

#include "pieces.h"


int** rookPaths(int oldX, int oldY, int newX, int newY);
int** bishopPaths(int oldX, int oldY, int newX, int newY);
int** knightPaths(int oldX, int oldY, int newX, int newY);
int** queenPaths(int oldX, int oldY, int newX, int newY);
int** kingPaths(int oldX, int oldY, int newX, int newY);





#endif