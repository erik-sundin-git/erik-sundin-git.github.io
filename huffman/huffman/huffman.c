//
//  huffman.c
//  huffman
//
//  Created by Erik on 2023-02-06.
//


#include "huffman.h"
#include "trie.h"
#include "pqueue.h"
#include "htable.h"
#include "encode_decode.h"

#define CHOICE argv[1]
#define ENCODE "-encode"
#define DECODE "-decode"


int main(int argc, const char * argv[]) {
    
    //Exit the program if the input is wrong.
    int input = validate_input(argc, argv);
    if (!input) {
        return 0;
    }

    //naming the input parameters
    const char *file_input_0 = argv[2];
    const char *file_input_1 = argv[3];
    const char *file_input_2 = argv[4];
   
    //Try to open files. Exit on failure.
    FILE *file_0;
    FILE *file_1;
    FILE *file_2;

    if ((file_0 = open_file(file_input_0, "r")) == NULL) {
        return 0;
    } else if ((file_1 = open_file(file_input_1, "r")) == NULL) {
        return 0;
    } else if ((file_2 = open_file(file_input_2, "w")) == NULL) {
        return 0;
    }
  
    //Create frequency table
    int *freq_table = freq_table_create(file_0);
    
    /* Create priority queue sorted with lowest priority first, using the
     * frequency table. 
     */
    pqueue *pq = trie_create_pq(freq_table, MAX_CAPACITY);


    // Create huffman trie
    trie *h_trie = trie_create_trie(freq_table, pq);


    //create and fill huffman table.
    htable *ht = htable_empty();
    char *path = calloc(50, sizeof(char));
    htable_fill(trie_get_root(h_trie), ht, 0, path);
    free(path);

    
    //encode
    if(strcmp(CHOICE, ENCODE) == 0) {
        text_encode(file_1, file_2, ht);
        long input_size = get_file_size(file_1);
        long output_size = get_file_size(file_2);

        printf("%ld bytes read from %s.\n", input_size, file_input_1);
        printf("%ld bytes used in encoded form.\n", output_size);

    }

    //decode
    if(strcmp(CHOICE, DECODE) == 0) {
        text_decode(file_1, file_2, h_trie);
        printf("File decoded succesfully.\n");
    }

    

    //cleanup
    fclose(file_0);
    fclose(file_1);
    fclose(file_2);

    htable_kill(ht);
    free(freq_table);
    
    trie_destroy(h_trie, trie_get_root(h_trie));
    pqueue_kill(pq);

    return 0;
}

long get_file_size(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long sz = ftell(fp);
    rewind(fp);
    
    return sz;
}

bool validate_input(int argc, const char *argv[]){
    // Validate amount of input parameters.
    if (argc != 5) {
        print_usage();
        return false;
    }

    // Validate filetype is of type txt for all files.
    for (int i = 2; i < 5; i++) {
        int length = strlen(argv[i]);
        if(strcmp(argv[i] + length - 4, ".txt") != 0) {
            printf("\n%s is not a .txt file. Exciting... \n", argv[i]);
            return false;
        }
    }

    //Validate if argument encode or decode is given.

     if ((strcmp(argv[1], "-encode") != 0) && (strcmp(argv[1], "-decode") !=0)) {
        fprintf(stderr, "Unknown argument: %s\n", argv[1]);
        print_usage();
        return false;
     }

    return true;    
}



void print_usage(void) {
    printf("USAGE: \n");
    printf("huffman [OPTION] [FILE0] [FILE1] [FILE2]\n");
    printf("Options:\n");
    printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
    printf("-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
}



FILE *open_file(const char *file, const char *mode) {
    FILE *fp;
    if ((fp = fopen(file, mode))== NULL) {
        fprintf(stderr, "Error reading file: %s\n", file);
    }
    return fp;
}

