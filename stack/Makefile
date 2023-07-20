.POSIX:
.SUFFIXES:
EXE=Stack
OBJECTS=test.o MLL.o Stack.o
CFLAGS = -g -Wall -O3
LDFLAGS=
CC=c99

$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXE) 
MLL.o: MLL.c MLL.h
test.o: test.c
Stack.o: Stack.c Stack.h
clean:
	rm *.o $(EXE)
valgrind: $(EXE)
	valgrind --leak-check=full ./$(EXE)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<