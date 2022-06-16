# Chess N-ary Trees

A fully functioning chess game in C which can be played in the terminal.
DSA Second Year final Project.

## Data Structures Used

1. Doubly Linked List
2. N-ary Trees
3. Dynamic Array
4. Static Array

## How to Install

Download the zip of the project.
In the linux terminal, type the following command:
gcc make main && ./main

## How to Play

### Initial Screen
![img1](https://user-images.githubusercontent.com/69706585/173981422-9dd15cba-8b8d-415f-9da2-bef4049703e7.png)
\nThe user is white, hence plays first

### Move Piece
The format to move the piece is as follows: oldX oldY, newX, newY\n\n

Example Move and Result:
![img2](https://user-images.githubusercontent.com/69706585/173981652-58122bf2-6d40-4aa7-bb38-dac8d9c946ca.png)
![img 3](https://user-images.githubusercontent.com/69706585/173981724-498fe2c4-dfa8-43f0-9bed-8418259d8957.png)


## Data Structures Used
1. Dynamic Arrays
2. Doubly Linked List
3. N-ary Trees

## Algorithmic Logic

1. For each piece, find all the possible places it can move (as if the piece was on an empty board)
2. For each move, check the path of the move. If that path does not contain any piece and if the last piece is of the opposite color, the move is accepted.
3. Using the logic, all possible moves of each piece is calculated.
4. Now using BFS, the next best possible move is calculated using a pre-determined scoring system.
5. The best move is stored and the move is taken. Then, the control goes back to the user.
6. Until either king is captured, the game continues.
