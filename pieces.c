#include "pieces.h"
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>


int rows = 8;
int cols = 8;


board initB(){
    board b = (board)malloc(rows*sizeof(board));
    for(int i = 0; i<8; i++){
        b[i] = (node**)malloc(cols*sizeof(node*));
        for(int j=0;j<8;j++){
            b[i][j] = (node*)malloc(sizeof(node));
        }
    }
    

    for(int i = 0; i<rows; i++){
        for(int j=  0; j<cols; j++){
            b[i][j]->points = 0;
            b[i][j]->x = i;
            b[i][j]->y = j;

            if(j<2) b[i][j]->color = 'w';
            if(j>5) b[i][j]->color = 'b';

            if((j==0 || j==7) && (i==0 || i ==7)) b[i][j]->type = 'r';
            else if((j==1||j==6) && (i==0 || i ==7)) b[i][j]->type = 'k';
            else if((j==2||j==5) && (i==0 || i ==7)) b[i][j]->type = 'b';
            else if((j==3) && (i==0 || i ==7)) b[i][j]->type = 'q';
            else if((j==4) && (i==0 || i ==7)) b[i][j]->type = 'g';
            else if(i==1 || i == 6) b[i][j]->type = 'p';
        }
    }

    return b;
}

void printB(board b){
    for(int i = 0; i<rows; i++){
        for(int j=  0; j<cols; j++){
            b[i][j]->points = 0;
            b[i][j]->x = i;
            b[i][j]->y = j;
        }
    }

    for(int i = 0; i<rows; i++){
        for(int j=  0; j<cols; j++){
            if(b[i][j]->type == '\0') printf(" ");
            else printf("%c " ,b[i][j]->type);
        }
        printf("\n");
    }
}

void movePiece(board* b, int oldX, int oldY, int newX, int newY){

    int** moves; //lists of all moves
    board board = *b;
    char oldType = board[oldX][oldY]->type;
    char oldColor = board[oldX][oldY]->color;
    char newType = board[oldX][oldY]->type;
    char newColor = board[oldX][oldY]->color;


    //check whether new and old coordinates are the same
    #pragma region 
    if((oldX == newX) && (oldY == newY)){
        printf("\nInvalid Move. Please try again. (call from movePiece) ");
        // movePiece(b, oldX, oldY, newX, newY);
    }
    #pragma endregion

    //moving piece from old coords to new coords
    #pragma region 
    
    board[oldX][oldY]->color = '\0';
    board[oldX][oldY]->points = 0;
    board[oldX][oldY]->type = '\0';

    board[newX][newY]->color = oldColor;
    board[newX][newY]->type = oldType;
    // printf("should be changed: %c", board[newX][newY]->type);
    #pragma endregion

    switch (oldType)
    {
    case 'r':
        moves = rookPaths(oldX, oldY, newX, newY);
        break;

    case 'b':
        moves = bishopPaths(oldX, oldY, newX, newY);
        break;

    case 'k':
        moves = knightPaths(oldX,oldY, newX, newY);
        break;

    case 'q':
        moves = queenPaths(oldX, oldY, newX, newY);
        break;
    
    case 'g':
        moves = kingPaths(oldX, oldY, newX, newY);
        break;
    
    default:
        printf("default (call from movePiece)\n");
        // printf("type causing default: %c\n", board[oldX][oldY]->type);

        break;
    }
    *b = board;    
}

int** allRookMoves(board b, int currX, int currY){
    int numMoves = 14;

    int** moves = (int**)malloc(sizeof(int*) * numMoves);
    int** movesValid = (int**)malloc(sizeof(int*) * numMoves);

    int j;
    //list of all rook moves
    #pragma region 
    //keeping y constant, changing x

    j =0 ;
    for(int i=0; i<7;i++){
        // if(i== currX && j== currY) {i--; j++; continue;}
        if(j == currX) {j++;i--;continue;}
        moves[i] = (int*)malloc(sizeof(int)*2);
        moves[i][0] = j++;
        moves[i][1] = currY;
    }
    //keeping x constant, changing y
    j = 0;
    for(int i =0; i<7;i++){
        if(j == currY) {i--; j++; continue;}
        moves[i+7] = (int*)malloc(sizeof(int)*2);
        moves[i+7][0] = currX;
        moves[i+7][1] = j++;
    }
    #pragma endregion

    // for(int i =0;i<numMoves; i++){
    //         printf("%d %d\n", moves[i][0], moves[i][1]);
    // }
    
    return moves;
}

int** allKnightMoves(board b, int oldX, int oldY){
    int numMoves =8; //max number of moves of a knight
    int movesCounter = 0;

    //initializing array
    int** moves = (int**)malloc(sizeof(int*) * numMoves);
    for(int i=0; i<numMoves; i++) moves[i] = (int*)malloc(sizeof(int)*2);

    int temp[4] = {-2, -1, 1, 2};
    int temp2[4] = {2, 1, -1, -2};

    //calc total number of moves possible
    for(int i=0; i<4; i++){
        int x = temp[i];
        for(int j=0; j<4; j++){
            int y = temp2[j];
            if(abs(x)==abs(y)) continue;

            if(isCoordInBoard(oldX + x, oldY + y)){
                moves[movesCounter][0] = oldX + x;
                moves[movesCounter++][1] = oldY + y;
            }
        }
    }
    return moves;
}

int** allBishopMoves(board b, int oldX, int oldY){
    int numMoves = 13; //max number of moves of bishop
    int movesCounter =0;

    int** moves = (int**)malloc(sizeof(int*) * numMoves);
    for(int i=0; i<numMoves; i++) moves[i] = (int*)malloc(sizeof(int)*2);

    int temp[2] = {-1,1};
    int temp2[2] = {1,-1};

    int k =1;
    int i,j;
    for(i =0; i<2; i++){
        for(j=0; j<2; j++){
            k = 1;
            while(isCoordInBoard(k*temp[i]+ oldX, k*temp[j]+ oldY)){
                moves[movesCounter][0] = k*temp[i] + oldX;
                moves[movesCounter++][1] = k*temp[j] + oldY;
                k++;
            }
        }
    }
    return moves;
}

int** allQueenMoves(board b, int oldX, int oldY){
    int numMoves= 13+14 ; //from bishop and rook
    int** bishopMoves = allBishopMoves(b, oldX, oldY);
    int** rookMoves = allRookMoves(b, oldX, oldY);

    // allocating memory to array
    #pragma region 
    int** moves = (int**)malloc(sizeof(int*)*numMoves);
    for(int i =0; i<numMoves; i++){
        moves[i] = (int*)malloc(sizeof(int)*2);
    }
    #pragma endregion

    //merging both arrays

    for(int i =0; i<14; i++){

        moves[i][0] = rookMoves[i][0];
        moves[i][1] = rookMoves[i][1];
        
        // printf("%d %d\n", moves[i+13][0], moves[i+13][1]);
    }

    for(int i =0; i<13; i++){
        moves[i+14][0] = bishopMoves[i][0];
        moves[i+14][1] = bishopMoves[i][1];
        // printf("%d %d\n", moves[i][0], moves[i][1]);
    }
    

    return moves;
}


int** validMoves(board b, int oldX, int oldY){
    
    int pathSize;
    int numPaths;
    int** paths;
    int isValid = 0;
    int validMovesCounter =0;
    int** allMoves;
    int pathX = 0;
    int pathY = 0;
    
    char initColor= b[oldX][oldY]->color;
    char type = b[oldX][oldY]->type;

    // printf("type: %c", type);

    //to set numPaths and int** allMoves
    switch (type)
    {
    case 'r':
        numPaths = 14;
        allMoves = allRookMoves(b, oldX, oldY);
        break;

    case 'k':
        numPaths = 8;
        allMoves= allKnightMoves(b, oldX, oldY);
        break; 

    case 'b':
        numPaths = 13;
        allMoves = allBishopMoves(b, oldX, oldY);
        break;

    case 'q':
        numPaths = 27;
        allMoves =allQueenMoves(b, oldX, oldY);
        break;
    
    default:
        printf("default switch case (call from validMoves)\n");
        break;
    }

    //initializing validMoves array
    int** validMoves = (int**)malloc(sizeof(int*)*numPaths);

    //looping through all finalMoves. For each, calculating the path and checking if move is valid.
    for(int i=0; i<numPaths; i++){
        int* coords = allMoves[i];
        int newX = coords[0];
        int newY = coords[1];

        //to set pathSize and int** paths
        switch (type)
        {
        case 'r':
            pathSize = (oldX == newX) ? abs(newY - oldY) : abs(newX - oldX);
            paths = rookPaths(oldX, oldY, newX, newY);
            break;

        case 'k':
            pathSize = 1;
            paths = knightPaths(oldX, oldY, newX, newY);
            break;

        case 'b':
            pathSize = abs(newX - oldX);
            paths = bishopPaths(oldX, oldY, newX, newY);
            break;

        case 'q':
            if(oldX==newX || oldY==newY)
                pathSize = (oldX == newX) ? abs(newY - oldY) : abs(newX - oldX); //from rook
            else
                pathSize = abs(newX-oldX); //from knight
            // printf("pathsize for queen = %d\n", pathSize);
            paths = queenPaths(oldX, oldY, newX, newY);
            break;
        
        default:
            break;
        }

        for(int j =0; j<pathSize; j++){
            

            pathX = paths[j][0];
            pathY = paths[j][1];

            // printf("Path sqaure %d: (%d %d)\n", j, paths[j][0], paths[j][1]);

            if(b[pathX][pathY]->type == '\0'){
                isValid = 1;
            }
            else{
                isValid = 0;
                break;
            }
        }

        //if different final colors
        //DO THIS LATER

        if(isValid) {
            // printf("is valid\n");
            validMoves[validMovesCounter] = (int*)malloc(sizeof(int)*2);
            validMoves[validMovesCounter][0] = newX;
            validMoves[validMovesCounter++][1] = newY;
        }   
        else ; //printf("\n");
        isValid =0;     
    }

    // for(int i =0;i<validMovesCounter;i++){
    //     printf("%d %d\n", validMoves[i][0], validMoves[i][1]);
    // }
    return validMoves;
}


//helpers
int getLenIntStarStar(int** arr){

    for(int i =0;i<18; i++){
        printf("%p\n", arr++);
    }

    return 0;
}

//update points of each piece

int isCoordInBoard(int x, int y){
    if(x>=0 && x<=7 && y>=0 && y<=7) return 1;
    else return 0;
}