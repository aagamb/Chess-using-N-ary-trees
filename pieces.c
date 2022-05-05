#include "pieces.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rows = 8;
int cols = 8;

board initBoard(){
    node** b = (node**) malloc(rows * sizeof(node*));
    for (int i = 0; i<rows; i++){
        b[i] = (node*)malloc(cols * sizeof(node));
    }
    for(int i = 0; i<rows; i++){
        for(int j=  0; j<cols; j++){
            b[i][j].points = 0;
            b[i][j].x = i;
            b[i][j].y = j;

            if(j<2) b[i][j].color = 'w';
            if(j>5) b[i][j].color = 'b';

            if((j==0 || j==7) && (i==0 || i ==7)) b[i][j].type = 'r';
            else if((j==1||j==6) && (i==0 || i ==7)) b[i][j].type = 'k';
            else if((j==2||j==5) && (i==0 || i ==7)) b[i][j].type = 'b';
            else if((j==3) && (i==0 || i ==7)) b[i][j].type = 'q';
            else if((j==4) && (i==0 || i ==7)) b[i][j].type = 'g';
            else if(i==1 || i == 6) b[i][j].type = 'p';
        }
    }

    return b;
}

void printBoard(board b){

    for(int i = 0; i<rows; i++){
        for(int j=  0; j<cols; j++){
            b[i][j].points = 0;
            b[i][j].x = i;
            b[i][j].y = j;
        }
    }

    for(int i = 0; i<rows; i++){
        for(int j=  0; j<cols; j++){
            printf("%c " ,b[i][j].type);
        }
        printf("\n");
    }

}

