.POSIX:
.SUFFIXES:
EXE=MLL
OBJECTS=test.o MLL.o MLLa.o
CFLAGS = -g -Wall -O3
LDFLAGS=
CC=c99

$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o MLL $(OBJECTS)
MLL.o: MLL.c MLL.h
MLLa.o: MLLa.c MLLa.h
test.o: test.c
clean:
	rm *.o $(EXE)
vg: $(EXE)
	valgrind --leak-check=full ./$(EXE)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<