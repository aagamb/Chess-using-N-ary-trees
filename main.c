#include "pieces.h"
#include "board.h"


int main(){

    board b = initB();

    // movePiece(&b, 1,3, 5,3);
    // movePiece(&b, 1,0, 7,5);

    // int** validMovesArr = pawnPaths(0,3,1,3);
    // int** validMovesArr = allQueenMoves(b, 0,3);
    int** validMovesArr = validMoves(b, 1,1);
    

    // printB(b);

    // printf("\n\nPiece %c list of valid moves: \n", b[1][5]->type);
    // for(int i =0;i<27;i++){
    //     printf("%d %d\n", validMovesArr[i][0], validMovesArr[i][1]);
    // }

    float eval = evaluateBoard(b);
    printf("\nThe evaluation of the board is: %f\n", eval);


    free(validMovesArr);
    free(b);

    

    

    return 0;
}