CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lm

all: huffman.o

debug: huffman.c trie.c list.c pqueue.c htable.c freq_table.c bit_buffer.c encode_decode.c
	$(CC) $(LDFLAGS) $(CFLAGS) -o huffman $^

	

huffman.o: huffman.c trie.c list.c pqueue.c htable.c freq_table.c bit_buffer.c encode_decode.c 
	$(CC) $(LDFLAGS) -o huffman $^



clean:
	rm -f myprog *.o
