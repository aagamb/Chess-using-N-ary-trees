#include "pieces.h"


int main(){

    board b = initB();
    // printB(b);
    // movePiece(&b, 1, 0, 5, 5);
    movePiece(&b, 1,3, 5,3);
    movePiece(&b, 1,0, 5,5);
    // movePiece(&b, 0,0, 0,3);
    // movePiece(&b, 2,0, 5,5);
    // movePiece(&b, 0, 0, 0, 6);
    

    // int** validMovesArr = allQueenMoves(b, 0,3);
    int** validMovesArr = validMoves(b, 1,5);
    // int** validMovesArr = pawnPaths(0,3,1,3);


    printB(b);

    printf("\n\nPiece %c list of valid moves: \n", b[1][5]->type);
    for(int i =0;i<27;i++){
        printf("%d %d\n", validMovesArr[i][0], validMovesArr[i][1]);
    }

    

    

    return 0;
}