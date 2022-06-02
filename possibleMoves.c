#include "possibleMoves.h"

int** rookPaths(int oldX, int oldY, int newX, int newY){

    int** moves; //lists of all moves

    //create list of the possible moves of piece of the piece
    #pragma region 
    //moving along x axis
    if(newY == oldY){

        //allocating space for the list of lists
        int numPaths = abs(oldX - newX);
        moves = (int**)malloc(sizeof(int*) * numPaths);
        for(int i=0; i<numPaths; i++){
            moves[i] = (int*)malloc(sizeof(int)*2); //for the two coordinates   
        }

        int k =0;
        if(newX < oldX){
            while(oldX != newX){
                oldX -=1;
                moves[k][0] = oldX;
                moves[k++][1] = newY;
            }
        }
        else{
            while(oldX != newX){
                oldX +=1;
                moves[k][0] = oldX;
                moves[k++][1] = newY;
            }
        }
        

        // printf("\npaths are:  ");
        // for(int i =0;i<numPaths; i++){
        //     printf("%d %d\n", moves[i][0], moves[i][1]);
        // }

    //moving along y axis
    }else if(newX == oldX){
        //allocating space for the list of lists
        int numPaths = abs(oldY - newY);

        moves = (int**)malloc(sizeof(int*) * numPaths);
        for(int i=0; i<numPaths; i++){
            moves[i] = (int*)malloc(sizeof(int)*2); //for the two coordinates   
        }
        int k =0;
        if(newY < oldY){
            while(oldY != newY){
                oldY -=1;
                moves[k][0] = newX;
                moves[k++][1] = oldY;
            }
        }
        else{
            while(oldY != newY){
                oldY +=1;
                moves[k][0] = newX;
                moves[k++][1] = oldY;
            }
        }

        // printf("\npaths are:  ");
        // for(int i =0;i<numPaths; i++){
        //     printf("%d %d\n", moves[i][0], moves[i][1]);
        // }
    }
    #pragma endregion
    
    return moves;
}

int** bishopPaths(int oldX, int oldY, int newX, int newY){
    int** moves;

    //create list of possible moves of bishop
    
    //malloc for list of lists of possible moves;
    int numPaths = abs(newX - oldX);
    moves = (int**)malloc(sizeof(int*) * numPaths);
    for(int i=0; i<numPaths; i++){
        moves[i] = (int*)malloc(sizeof(int)*2); //for the two coordinates   
    }

    int k =0;
    if(newX<oldX && newY>oldY){
        while(oldX!=newX){
            moves[k][0] = --oldX;
            moves[k++][1] = ++oldY;
        }
    }
    else if(newX>oldX && newY <oldY){
        while(oldX!=newX){
            moves[k][0] = ++oldX;
            moves[k++][1] = --oldY;
        }
    }
    else if(newX > oldX && newY > oldY){
        while(oldX!=newX){
            moves[k][0] = ++oldX;
            moves[k++][1] = ++oldY;
        }
    }
    else if(newX < oldX && newY < oldY){
        while(oldX!=newX){
            moves[k][0] = --oldX;
            moves[k++][1] = --oldY;
        }
    }

    return moves;
}

int** knightPaths(int oldX, int oldY, int newX, int newY){
    int** moves;

    moves = (int**)malloc(sizeof(int*)*1);
    moves[0] = (int*)malloc(sizeof(int)*2);
    moves[0][0] = newX;
    moves[0][1] = newY;
    return moves;
}

int** queenPaths(int oldX, int oldY, int newX, int newY){
    // int** rookMovesArr = rookMoves(oldX, oldY, newX, newY);
    // int** bishopMovesArr = bishopMoves(oldX, oldY, newX, newY);

    // int lenRookMovesArr = sizeof(rookMovesArr[0])/sizeof(rookMovesArr[0][0]);
    // int lenBishopMovesArr = sizeof(bishopMovesArr[0])/sizeof(bishopMovesArr[0][0]);

    // int pathSize = lenRookMovesArr + lenBishopMovesArr;
    // int** paths = (int**)malloc(sizeof(int*)*4);
    // memcpy(paths, rookMovesArr, lenRookMovesArr * sizeof(int*));
    // memcpy(paths + lenRookMovesArr, bishopMovesArr, lenBishopMovesArr * sizeof(int*));


    // paths = bishopMovesArr;
    // printf("Pathsize is: %d", pathSize);
    // printf("\npaths are:  ");
    //     for(int i =0;i<10; i++){
    //         printf("%d %d\n", paths[i][0], paths[i][1]);
    //     }

    if(oldX == newX || oldY  == newY) return rookPaths(oldX, oldY, newX, newY);
    else return bishopPaths(oldX, oldY, newX, newY);
}

int** kingPaths(int oldX, int oldY, int newX, int newY){
    int** moves;

    moves = (int**)malloc(sizeof(int*)*1);
    moves[0] = (int*)malloc(sizeof(int)*2);
    moves[0][0] = newX;
    moves[0][1] = newY;
    return moves;
}

int** pawnPaths(int oldX, int oldY, int newX, int newY){
    int** moves;

    moves = (int**)malloc(sizeof(int*)*1);
    moves[0] = (int*)malloc(sizeof(int)*2);
    moves[0][0] = newX;
    moves[0][1] = newY;
    return moves;
}



