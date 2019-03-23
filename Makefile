CC=gcc
CFLAGS=-I
DEPS=hashtable.h
OBJ=hashtable.o test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(FLAGS) --std=c99

test-hash: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) --std=c99 

