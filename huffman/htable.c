#include "htable.h"

#define MAX_PATH_LENGTH 50

struct htable {
    char **table;
};



//FIXME: ta bort sen
void htable_fill(q_node *trie_root, htable *tb, int index, char *path) {
    int pos = index;
    
    if(trie_node_is_leaf(trie_root)) {
        int val = trie_node_get_value(trie_root);  
        strncpy(tb->table[val], path, pos);
    }
    
    if (trie_node_left_child(trie_root) != NULL) {
        path[pos] = '0';
        pos++;
        htable_fill(trie_node_left_child(trie_root), tb, pos, path);
    }

    if(pos > 0) {
        pos--;
    }
    
    if (trie_node_right_child(trie_root) != NULL) {
        path[pos] = '1';
        pos++;
        htable_fill(trie_node_right_child(trie_root), tb, pos, path);
    }
}



char *htable_get_code(htable *table, int character) {
    return table->table[character];
}

htable *htable_empty() {

    htable *new;
    if((new = malloc(sizeof(htable))) == NULL) {
        fprintf(stderr, "Unable to allocate memoory for htable\n");
    }
    new->table = calloc(256, sizeof(char*));
    for (int i = 0; i < 256; i ++) {
        new->table[i] = calloc(MAX_PATH_LENGTH, sizeof(char));
    }

    return new;
}

void htable_kill(htable *table) {
    for (int i = 0; i < 256; i ++) {
        free(table->table[i]);
    } 
    free(table->table);
    free(table);
}

/**** Utility functions not part of API ****/


void print_htable(htable *table, int *freq_table) {
    for (int i = 0; i < 256; i++) {
        if (freq_table[i] > 0) {
            printf("char: %2c | %3d freg: %2d code: %s\n",i ,i, freq_table[i] ,table->table[i]);
        }
    }
}