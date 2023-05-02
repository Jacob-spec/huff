CC=gcc
CFLAGS=-g -Wall
OBJ=compressor.o character.o 

%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

lz: lz.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o lz
