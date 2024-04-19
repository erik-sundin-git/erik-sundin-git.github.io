#include <stdio.h>

#include "freq_table.h"
#include "trie.h"
#include "pqueue.h"
#include "bit_buffer.h"

int main(int argc, char const *argv[]) {
    int size = 5;
    FILE *freq = fopen("test.txt", "r");

    

    bit_buffer *b = bit_buffer_empty();
    for (int i = 0; i < 10; i++) {
        bit_buffer_insert_bit(b,1);
    }

    while(bit_buffer_size(b) > 0) {
        printf("%d", bit_buffer_remove_bit(b));
    }

    printf("\n");

    for (int i = 0; i < 10; i++) {
        bit_buffer_insert_bit(b,1);
    }

    bit_buffer_remove_bit(b);
    bit_buffer_insert_bit(b,0);
    while(bit_buffer_size(b) > 0) {
        printf("%d", bit_buffer_remove_bit(b));
    }

    return 0;
}
