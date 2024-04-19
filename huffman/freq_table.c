#include "freq_table.h"

int *freq_table_create(FILE *file) {
    int *freq_table;
    freq_table = (int*) calloc(MAX_CAPACITY, sizeof(int));
    if (freq_table == NULL) {
        fprintf(stderr, "Error allocating memory for frequency table\n");
    }


    int character = 0;
    while ((character = fgetc(file)) != EOF) {
        freq_table[character]++;
    }
    return freq_table;
}



void freq_table_print(int *table) {
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (table[i] > 0)
            printf("%2c | %2d\n", (char)i, table[i]);
  }
}