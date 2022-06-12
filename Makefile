main : main.o board.o pieces.o possibleMoves.o
	cc -o main main.o board.o pieces.o possibleMoves.o	
main.o : main.c board.c pieces.c possibleMoves.c board.h pieces.h possibleMoves.h
	cc -c main.c -o main.o	
board.o : board.o board.h
	cc -c board.c -o board.o
pieces.o : pieces.c pieces.h
	cc -c pieces.c -o pieces.o
possibleMoves.o : possibleMoves.c possibleMoves.h
	cc -c possibleMoves.c -o possibleMoves.o
clean : 
	rm *.o
