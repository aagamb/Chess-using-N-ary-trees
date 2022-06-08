#include "pieces.h"
#include "board.h"

//issues to fix
// 1. making int* of moves, the empty moves are 0,0. This should be changed to -1,-1. Hence, change listAllBoards after this change is done

int main(){

    board b = initB();

    // movePiece(&b, 1,0, 5,4);
    // movePiece(&b, 1,3, 5,4);
    // movePiece(&b, 1,3, 7,5);

    //TO DO
    //TO ALL MOVES OF EACH PIECE, ADD THE FINAL MOVE AS WELL IF THE COLOR IS THE OPPOSITE COLOR, ELSE DO NOTHING


    // int** validMovesArr = rookPaths(0,0 , 0 ,5);
    // int** validMovesArr = allKingMoves(b, 3,4);

    // int numValidMoves = 0;
    // int** validMovesArr = validMoves(b, 0,3, &numValidMoves);
    
    listNode* tail = listAllBoards2(&b, 'w');

    printB(b);

    // printf("\n\nPiece %c list of valid moves: \n", b[0][3]->type);
    // for(int i =0;i<27;i++){
    //     printf("%d %d\n", validMovesArr[i][0], validMovesArr[i][1]);
    // }

    // float eval = evaluateBoard(b);
    // printf("\nThe evaluation of the board is: %f\n", eval);

    int numBoards = 0;

    while(tail){
        tail = tail->prev;
        numBoards+=1;
        // printB(tail->b);
        break;
    }
    // printf("\nnumBoards: %d", numBoards);


    // free(validMovesArr);
    free(b);



    return 0;
}