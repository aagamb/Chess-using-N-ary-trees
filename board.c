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
    // printf("(from evaluateBoard) score is: %f", score);
    return score;
}

listNode2* newBoardNode2(board b){
    listNode2* nn = (listNode2*)malloc(sizeof(listNode2));    
    nn->next = NULL;
    nn->prev = NULL;
    board temp;

    // Mallocing memory for new board
    #pragma region 
    temp= (board)malloc(8*sizeof(board));
    for(int i = 0; i<8; i++){
        temp[i] = (node**)malloc(8*sizeof(node*));
        for(int j=0;j<8;j++){
            temp[i][j] = (node*)malloc(sizeof(node));
        }
    }
    #pragma endregion

    for(int i = 0; i<8; i++){
        for(int j =0; j<8; j++){
            temp[i][j]->color = b[i][j]->color;
            temp[i][j]->type = b[i][j]->type;
            temp[i][j]->x = b[i][j]->x;
            temp[i][j]->y = b[i][j]->y;
        }
    }
    nn->b = temp;
    return nn;
}

listNode2* listAllBoards2(board* b, char c){

    board funcBoard = *b;
    int numMoves = 0;
    int** moves;
    listNode2* tail = NULL;
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
                    if(!tail) tail = newBoardNode2(*b);
                    else {
                        tail->next = newBoardNode2(*b);
                        // printB(tail->next->b);
                        tail->next->prev = tail;
                        tail = tail->next;
                    }

                    

                    //undoing the move
                    movePiece(b, moves[k][0], moves[k][1], i, j);

                    
                    // if(tail->prev)
                    //     printB(tail->prev->b);
                }
                
            }
        }
    }
    return tail;
}

int minimax(int depth, board* b, char c){

    int boardValue;
    if (depth == 0)
        return evaluateBoard(*b);

    listNode2* allBoards = listAllBoards2(b, 'w');
    // minimax(depth-1, &allBoards->b, 'b');

    // //if maximizer
    if(c == 'w'){
        boardValue = INT_MIN;
        while (allBoards)
        {
            boardValue = max(boardValue, minimax(depth-1, &allBoards->b, 'b'));
            allBoards = allBoards->prev;
        }
    }
    else{
        boardValue = INT_MAX;
        while(allBoards){
            boardValue = min(boardValue, minimax(depth-1, &allBoards->b, 'w'));
            allBoards = allBoards->prev;
        }
    }

}


mmnode* createmmNode(board* b, int score){
    mmnode* temp = (mmnode*)malloc(sizeof(mmnode));
    temp->b = b;
    temp->score = score;
    return temp;
}

mmnode* minimax2(int depth, board* b, char c, mmnode** outermmNode){  
    mmnode* mmNode;  
    if (depth == 0){
        *outermmNode = createmmNode(b, evaluateBoard(*b));
        mmNode = createmmNode(b, evaluateBoard(*b));
        // printf("\n");
        // printB(*b);
        printf("the score is: %d\n", mmNode->score);
        return mmNode;
    }

    int boardValue;
    listNode2* allBoards = listAllBoards2(b, 'w');

    // maximize
    if(c=='w'){
        boardValue = INT_MIN;
        while(allBoards){
            if(minimax2(depth-1, &(allBoards->b), 'b', outermmNode))
                boardValue = max(boardValue, minimax2(depth-1, &(allBoards->b), 'b', outermmNode)->score);
            allBoards = allBoards->prev;
        }
    }
    else if(c=='b'){
        boardValue = INT_MAX;
        while(allBoards){
            boardValue = min(boardValue, minimax2(depth-1, &(allBoards->b), 'w', outermmNode)->score);
            allBoards = allBoards->prev;
        }
    }
    else{
        return mmNode;
    }
}

mmnode* hardmm(int depth, board* b, char c, mmnode** outermmNode){
    int boardValue;

    //maximize
    // if(depth==2){
    //     boardValue = INT_MIN;
    //     listNode2* allBoards = listAllBoards2(b, 'w');

    //     //REMOVE THIS LINE WHEN EXTRA DEPTH IS ADDED
    //     (*outermmNode)->score = boardValue;

    //     while(allBoards){
    //         int currBoardScore = evaluateBoard(allBoards->b);
    //         printf("%d \n", currBoardScore);
    //         if( currBoardScore > (*outermmNode)->score){
    //             *outermmNode = createmmNode(&allBoards->b, currBoardScore);
    //             boardValue = currBoardScore;
    //         }
    //         allBoards = allBoards->next;
    //     }

    // }
    // depth--;
    // printB(*(*outermmNode)->b);
    if(depth == 1){
        boardValue = INT_MIN;
        listNode2* allBoards = listAllBoards2((*outermmNode)->b, 'w');

        //REMOVE THIS LINE WHEN EXTRA DEPTH IS ADDED
        (*outermmNode)->score = boardValue;

        while (allBoards){
            int currBoardScore = evaluateBoard(allBoards->b);
            // printf("%d \n", currBoardScore);
            if( currBoardScore > (*outermmNode)->score){
                *outermmNode = createmmNode(&allBoards->b, currBoardScore);
                boardValue = currBoardScore;
            }
            allBoards = allBoards->next;
        }
    }

    if(depth == 0){
        // mmnode* mmNode = createmmNode(b, evaluateBoard(*b));

        // return mmNode;
    }
}

int isMoveValid(board b, int oldX, int oldY, int newX, int newY){

    int numValidMoves;
    int** listValidMoves = validMoves(b, oldX, oldY, &numValidMoves);
    int isValid =0;

    if(!listValidMoves)
        return 0;

    if(b[oldX][oldY]->color != 'b')
        return 0;
         
    for(int i =0; i<numValidMoves; i++){
        int vnewX = listValidMoves[i][0]; //stands for valid newX
        int vnewY = listValidMoves[i][1];

        if((newX == vnewX) && (newY == vnewY)){
            isValid = 0;
            return 1;
        }
    }
    return isValid;
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

int max(int a, int b){
    return (a>b) ? a : b;
}

int min(int a, int b){
    return (a<b) ? a : b;
}


