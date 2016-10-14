CC=gcc -Wall -g 
CFLAGS=
OBJ=Huffman.o HuffmanCode.o
HEAD=huffman.h

All: Huffman outros

Huffman: $(OBJ)
	$(CC) $(OBJ) -o $@ $(CFLAGS)

Huffman.o: Huffman.c $(HEAD)
	$(CC) -c Huffman.c $(CFLAGS)
	

HuffmanCode.o: HuffmanCode.c huffman.h 
	$(CC) -c HuffmanCode.c $(CFLAGS)



outros:
	rm *.o

clean:
	rm Huffman