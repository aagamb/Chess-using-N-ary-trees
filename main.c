#include "pieces.h"


int main(){

    board b = initB();
    // printB(b);
    // movePiece(&b, 1, 0, 5, 5);
    movePiece(&b, 1,3, 2,3);
    // movePiece(&b, 0, 0, 0, 6);
    
    int oldX = 0;
    int oldY = 0;
    int newX = 4;
    int newY = 0;

    
    int** validMovesArr = validMoves(b, 0, 2);

    // for(int i =0;i<14;i++){
    //     printf("%d %d\n", validMovesArr[i][0], validMovesArr[i][1]);
    // }

    

    printB(b);

    return 0;
}