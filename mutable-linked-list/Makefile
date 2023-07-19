.POSIX:
.SUFFIXES:
EXE=MLL
OBJECTS=test.o MLL.o
CFLAGS = -g -Wall -O3
LDFLAGS=
CC=c99

$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o MLL MLL.o test.o
MLL.o: MLL.c MLL.h
test.o: test.c
clean:
	rm *.o $(EXE)
valgrind: $(EXE)
	valgrind --leak-check=full ./$(EXE)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<