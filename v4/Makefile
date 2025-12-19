CC = gcc
CFLAGS = -Wall -Wextra
OBJ = calculator.o parseInput.o doOperation.o

calculator: $(OBJ)
	$(CC) $(CFLAGS) -o calculator $(OBJ)

calculator.o: calculator.c
	$(CC) $(CFLAGS) -c calculator.c -o calculator.o

parseInput.o: parseInput.c parseInput.h
	$(CC) $(CFLAGS) -c parseInput.c -o parseInput.o

doOperation.o: doOperation.c doOperation.h
	$(CC) $(CFLAGS) -c doOperation.c -o doOperation.o

clean:
	rm -f calculator *.o
