#ifndef PIECES_H_INCLUDED
#define PIECES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

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

#endif


