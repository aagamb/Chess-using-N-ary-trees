#include "board.h"


//Reference link: https://www.chessprogramming.org/Evaluation
// You can add number of valid moves to evaluateBoard
float evaluateBoard(board b){
    float score =0;
    float k;
    for(int x=0; x<8; x++){
        for(int y=0; y<8; y++){
            node* piece =b[x][y];
            char type = piece->type;
            

            // k is a multiplier, adds for white pieces, subtracts for black pieces
            if(piece->color == 'w') k = 1.0;
            else if(piece->color == 'b') k = -1.0;
            else continue;

            // printf("type is: %c \n", type);
            switch (type)
            {
            case 'r':
                score = score + k*5;
                break;
            case 'k':
                score += k*3;
                break;
            case 'b':
                score += k*3;
                break;
            case 'q':
                score += k*9;
                break;
            case 'g':
                score += k*200;
                break;
            case 'p':
                score += k*1;
                break;
            default:
                break;
            }
        }
    }
    printf("score is: %f", score);
    return score;
}