CC=gcc
CFLAGS=-g 
OBJ=compressor.o character.o sort.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

huff: huff.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o huff
