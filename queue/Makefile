.POSIX:
.SUFFIXES:
EXE=Queue
OBJECTS=test.o Queue.o
CFLAGS = -g -Wall -O3
LDFLAGS=
CC=c99

$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXE)
test.o: test.c
Queue.o: Queue.c Queue.h
clean:
	rm *.o $(EXE)
vg: $(EXE)
	valgrind --leak-check=full ./$(EXE)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<