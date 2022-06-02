#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "pieces.h"
#include "limits.h"

typedef struct listNode{
    struct listNode* prev;
    board b;
    struct listNode* next;
}listNode;

listNode* newBoardNode(board b);
float evaluateBoard(board b);
listNode* listAllBoards(board* b, char c);

#endif