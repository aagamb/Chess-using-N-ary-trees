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

listNode* newBoardNode(board b){
    listNode* nn = (listNode*)malloc(sizeof(listNode));
    nn->b = b;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

listNode* newBoardNodeTemp(board* b){
    listNode* nn = (listNode*)malloc(sizeof(listNode));
    nn->b = *b;
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

listNode* listAllBoards(board* b, char c){

    board funcBoard = *b;
    int numMoves = 0;
    int** moves;
    listNode* tail = NULL;
    int numValidMoves = 0;

    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            //there is a piece there
            if((funcBoard[i][j]->type != '\0') && (funcBoard[i][j]->color==c)){
                char type = funcBoard[i][j]->type;
                 //get all the moves of the piece over there. move the piece in the board and add it to listAllBoards
                switch (type)
                {
                case 'r':
                    numMoves= 14;               
                    break;

                case 'k':
                    numMoves= 8;
                    break;

                case 'b':
                    numMoves= 13;               
                    break;

                case 'q':
                    numMoves= 27;
                    break;

                case 'g':
                    numMoves =8;
                    break;
                
                default:
                    break;
                }
                
                moves= validMoves(funcBoard, i, j, &numValidMoves);
                for(int k = 0; k<numValidMoves; k++){
                    if(moves[k][0] == 0 && moves[k][1] == 0) continue;

                    movePiece(b, i, j, moves[k][0], moves[k][1]);
        
                    //adding node to linked list of boards
                    //if first node
                    if(!tail) tail = newBoardNode(*b);
                    else {
                        tail->next = newBoardNode(*b);
                        // printB(tail->next->b);
                        tail->next->prev = tail;
                        tail = tail->next;
                    }

                    

                    //undoing the move
                    movePiece(b, moves[k][0], moves[k][1], i, j);

                    
                    if(tail->prev)
                        printB(tail->prev->b);
                }
                
            }
        }
    }
    return tail;
}

listNode* listAllBoards2(board* b, char c){

    board funcBoard = *b;
    int numMoves = 0;
    int** moves;
    listNode* tail = NULL;
    int numValidMoves = 0;

    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            //there is a piece there
            if((funcBoard[i][j]->type != '\0') && (funcBoard[i][j]->color==c)){
                char type = funcBoard[i][j]->type;
                 //get all the moves of the piece over there. move the piece in the board and add it to listAllBoards
                switch (type)
                {
                case 'r':
                    numMoves= 14;               
                    break;

                case 'k':
                    numMoves= 8;
                    break;

                case 'b':
                    numMoves= 13;               
                    break;

                case 'q':
                    numMoves= 27;
                    break;

                case 'g':
                    numMoves =8;
                    break;
                
                default:
                    break;
                }
                
                moves= validMoves(funcBoard, i, j, &numValidMoves);
                for(int k = 0; k<numValidMoves; k++){
                    if(moves[k][0] == 0 && moves[k][1] == 0) continue;

                    movePiece(b, i, j, moves[k][0], moves[k][1]);
        
                    //adding node to linked list of boards
                    //if first node
                    if(!tail) tail = newBoardNode(*b);
                    else {
                        tail->next = newBoardNode(*b);
                        // printB(tail->next->b);
                        tail->next->prev = tail;
                        tail = tail->next;
                    }

                    

                    //undoing the move
                    movePiece(b, moves[k][0], moves[k][1], i, j);

                    
                    if(tail->prev)
                        printB(tail->prev->b);
                }
                
            }
        }
    }
    return tail;
}

/*
int minimax(int depth, board b, bool maximizer){
    if depth == 0 return evaluateBoard(b)
    int boardValue;
    allBoards = listOfAllBoards(b) //linked list

    if(maximizer){
        boardValue = INT_MIN;
        while(allBoards){
            boardValue = max(boardValue, minimax(depth-1, allBoards.board, false))
            allBoards = allBoards.next
    }
    else{
        boardValue = INT_MAX
        while(allBoards){
            boardValue = min(boardValue, minimax(depth-1, allBoards.board, true))
        }
    } 
}
*/



