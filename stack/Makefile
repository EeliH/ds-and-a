.POSIX:
.SUFFIXES:
EXE=Stack
OBJECTS=test.o Stack.o
CFLAGS = -g -Wall -O3
LDFLAGS=
CC=c99

$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXE) 
test.o: test.c
Stack.o: Stack.c Stack.h
clean:
	rm *.o $(EXE)
vg: $(EXE)
	valgrind --leak-check=full ./$(EXE)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) -c $<