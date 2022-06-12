#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "pieces.h"
#include "limits.h"
#include "stdbool.h"

// typedef struct listNode{
//     struct listNode* prev;
//     board b;
//     struct listNode* next;
// }listNode;

typedef struct listNode2{
    struct listNode2* prev;
    board b;
    struct listNode2* next;
}listNode2;

typedef struct mmnode{
    board* b;
    int score;
}mmnode;

// listNode* newBoardNode(board b);
listNode2* newBoardNode2(board b);
float evaluateBoard(board b);
// listNode* listAllBoards(board* b, char c);
listNode2* listAllBoards2(board* b, char c);
int minimax(int depth, board* b, char c);
mmnode* minimax2(int depth, board* b, char c, mmnode** outermmNode);
mmnode* createmmNode(board* b, int score);
mmnode* hardmm(int depth, board* b, char c, mmnode** outermmNode);
int isMoveValid(board b, int oldX, int oldY, int newX, int newY);

//helpers
int max(int a, int b);
int min(int a, int b);


#endif