PROGRAM = a.out
OBJFILES = Card.o Game.o main.o Player.o 
CC = g++ 
CFLAGS = -std=c++0x


all:
	
	$(CC) $(CFLAGS) -c Card.cpp -o Card.o
	$(CC) $(CFLAGS) -c Game.cpp -o Game.o
	$(CC) $(CFLAGS) -c main.cpp -o main.o
	$(CC) $(CFLAGS) -c Player.cpp -o Player.o
	$(CC) $(OBJFILES) -o $(PROGRAM)
	
