CC=clang
CFLAGS=-g 
OBJ=compressor.o character.o queue.o tree.o

%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

huff: huff.c $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o huff
