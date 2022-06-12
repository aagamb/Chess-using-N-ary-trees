#include "pieces.h"
#include "board.h"

//issues to fix
// 1. making int* of moves, the empty moves are 0,0. This should be changed to -1,-1. Hence, change listAllBoards after this change is done

int main(){

    #pragma region commented
    // board b = initB();

    // movePiece(&b, 1,0, 2,0);
    // movePiece(&b, 1,1, 1,2);
    // movePiece(&b, 6,1,5,1);
    // movePiece(&b, 6,4, 5, 4);
    // // movePiece(&b, 5,0,1,4);
    // printB(b);

    // mmnode* outermmNode = createmmNode(&b, INT_MIN);
    // // minimax2(1, &b, 'w', &outermmNode);
    // hardmm(1, &b, 'w', &outermmNode);
    // printB((*outermmNode->b));    

    // printf("\nthe score is: %d", outermmNode->score);

    // int isValid = isMoveValid(b, 7, 5, 6, 4);
    // printf("\nis the move valid: %d\n", isValid); //take another piece

    
    // movePiece(&b, 6,1, 4,1);
    // movePiece(&b, 1,3, 5,4);
    // movePiece(&b, 1,3, 7,5); 


    // int** validMovesArr = rookPaths(0,0 , 0 ,5);
    // int** validMovesArr = allPawnMoves(b, 6, 0);  
    // int numValidMoves = 0;
    // int** validMovesArr = validMoves(b, 6, 0, &numValidMoves);
    
    // listNode2* tail = listAllBoards2(&b, 'w');

    // printf("\n\nPiece %c list of valid moves: \n", b[6][0]->type);
    // for(int i =0;i<27;i++){
    //     printf("%d %d\n", validMovesArr[i][0], validMovesArr[i][1]);
    // }

    // float eval = evaluateBoard(b);
    // printf("\nThe evaluation of the board is: %f\n", eval);

    // int numBoards = 0;

    // while(tail){
    //     printB(tail->b);
    //     tail = tail->prev;
    //     numBoards+=1;
    // }
    // printf("\nnumBoards: %d", numBoards); 

    
    
    // free(validMovesArr);

    #pragma endregion


    #pragma region running program
    board b = initB();
    mmnode* outermmNode = createmmNode(&b, INT_MIN);
    printB(b);

    int oldX, oldY, newX, newY;
    
    while(abs(evaluateBoard(b))<=200){
        int isValidMove = 0;

        #pragma region getting coordinates of moves
        while(!isValidMove){
            printf("From the position to move numbers: ");
            scanf("%d %d, %d %d", &oldX, &oldY, &newX, &newY);
            isValidMove = isMoveValid(b, oldX, oldY, newX, newY);
            if(!isValidMove)
                printf("Invalid Move. Try again.\n");
        }
        #pragma endregion

        movePiece(&b, oldX, oldY, newX, newY);

        outermmNode = createmmNode(&b, INT_MIN);
        hardmm(1, &b, 'w', &outermmNode);

        b = *(outermmNode->b);
        system("clear");

        printB(b);

        printf("\n");
        // printf("Pieces which you can move:\n");
        // printBlackB(b);
        // printf("\n");
    }

    if(evaluateBoard(b)>200)
        printf("\nYou have lost to a computer.");

    else{
        printf("\nYou won!.");
    }
    #pragma endregion

    free(b);
    return 0;
}