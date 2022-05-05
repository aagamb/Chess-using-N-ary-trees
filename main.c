#include "pieces.h"


int main(){

    board b = initB();
    // printB(b);
    movePiece(&b, 0, 0, 4, 0);

    printB(b);

    return 0;
}