#include "pieces.h"


int main(){

    board b = initB();
    // printB(b);
    movePiece(&b, 1, 0, 5, 5);
    movePiece(&b, 0,1, 7,7);
    // movePiece(&b, 0, 0, 0, 6);
    


    
    int** allMoves  = allRookMoves(b, 0, 0);
    int** validMovesArr = validMoves(b, allMoves, 0, 0);

    // for(int i =0;i<14;i++){
    //     printf("%d %d\n", validMovesArr[i][0], validMovesArr[i][1]);
    // }

    

    printB(b);

    return 0;
}