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

    int** paths; //lists of all paths
    board board = *b;
    char oldType = board[oldX][oldY]->type;
    char oldColor = board[oldX][oldY]->color;
    char newType = board[oldX][oldY]->type;
    char newColor = board[oldX][oldY]->color;


    //check whether new and old coordinates are the same
    #pragma region 
    if((oldX == newX) && (oldY == newY)){
        printf("\nInvalid Move. Please try again.");
        movePiece(b, oldX, oldY, newX, newY);
    }
    #pragma endregion

    //create list of the path of the piece
    //moving along x axis
    if(newY == oldY){

        //allocating space for the list of lists
        int numPaths = abs(oldX - newX);
        paths = (int**)malloc(sizeof(int*) * numPaths);
        for(int i=0; i<numPaths; i++){
            paths[i] = (int*)malloc(sizeof(int)*2); //for the two coordinates
            
        }
        //HERERERERERERERE
        for(int temp = oldX - newX-1; temp>=0; temp--){
            paths[temp][0] = temp;
            paths[3][1] = newY;
        }
        printf("\npaths are:  ");
        for(int i =0;i<numPaths; i++){
            printf("%d %d\n", paths[i][0], paths[i][1]);
        }

    }

    //moving piece from old coords to new coords
    #pragma region 
    

    board[oldX][oldY]->color = '\0';
    board[oldX][oldY]->points = 0;
    board[oldX][oldY]->type = '\0';

    board[newX][newY]->color = oldColor;
    board[newX][newY]->type = oldType;
    #pragma endregion



    *b = board;    
}

//update points of each piece
