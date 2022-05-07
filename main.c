#include "pieces.h"


int main(){

    board b = initB();
    // printB(b);
    movePiece(&b, 0, 2, 0, 4);

    int** allMoves  = allRookMoves(b, 4, 4);
    isMoveValid(b, allMoves, 4, 4);

    

    printB(b);

    return 0;
}