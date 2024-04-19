#include "encode_decode.h"

#define EOT '\4'

typedef q_node node_pos;

/**** Internal functions *****/

static void pad_bit_buffer(bit_buffer *b) {
    while((bit_buffer_size(b) % 8)  != 0) {
        bit_buffer_insert_bit(b, 0);
    }
}



static void insert_code_bit_buffer(char *code, bit_buffer *b) {
    for (int i = 0; i < strlen(code); i++) {
            if (code[i] == '0')
                bit_buffer_insert_bit(b, 0);
            else
                bit_buffer_insert_bit(b, 1);
    }
}


/****** External functions ******/

void text_encode(FILE *in_file, FILE *out_file,  htable *tb) {
    bit_buffer *b = bit_buffer_empty();
    int c;
    char *code;

    // While not EOF
    while((c = fgetc(in_file))!= EOF) {

        code = htable_get_code(tb, c);
        insert_code_bit_buffer(code, b);

        while(bit_buffer_size(b) >= 8) {
            fputc(bit_buffer_remove_byte(b), out_file);
        }
    }
    //Add EOT
    code = htable_get_code(tb, EOT);
    insert_code_bit_buffer(code, b);

    //pad the the last byte if needed and insert the remaining data.
    while (bit_buffer_size(b) != 0) {
        pad_bit_buffer(b);
        fputc(bit_buffer_remove_byte(b), out_file);
    }
    bit_buffer_free(b);
}





void text_decode(FILE *in_file, FILE *out_file, trie *h_trie) {
    node_pos *pos = trie_get_root(h_trie);
    bit_buffer *b = bit_buffer_empty();
    int encoded_c;
    int decoded_c = 0; 

    while(((encoded_c = fgetc(in_file)) != EOF) && decoded_c != EOT) {
        bit_buffer_insert_byte(b, encoded_c);
    }

    while ((bit_buffer_size(b) > 0) && decoded_c != EOT) {
        if(trie_node_is_leaf(pos)) {
            decoded_c = trie_node_get_value(pos);
            if(decoded_c != EOT) {
                fputc(decoded_c, out_file);
                pos = trie_get_root(h_trie);
            }
        }
        
        int bit = bit_buffer_remove_bit(b);
        if (bit == 0) {
            pos = trie_node_left_child(pos);
        } else {
            pos = trie_node_right_child(pos);
        } 
    }
    bit_buffer_free(b);
}





//FIXME: TA BORT
void text_decode_gam(FILE *in_file, FILE *out_file, trie *h_trie) {
    node_pos *pos = trie_get_root(h_trie);
    bit_buffer *b = bit_buffer_empty();
    int encoded_c;
    int decoded_c;

//TODO: ändra till feof
    while(((encoded_c = fgetc(in_file)) != EOF) || decoded_c != EOT) {
        //insert ecnoded_c into bitbuffer
        bit_buffer_insert_byte(b, encoded_c);
        //while pos != leaf and not EOT
        while(!(trie_node_is_leaf(pos)) && (decoded_c != EOT)) {
            //read bit from bitbuffer
            int bit = bit_buffer_remove_bit(b);
            if (bit == 0) {
                pos = trie_node_left_child(pos);
            } else {
                pos = trie_node_right_child(pos);
            }
        
            if(trie_node_is_leaf(pos)) {
                decoded_c = trie_node_get_value(pos);
                if(decoded_c != EOT) {
                    fputc(decoded_c, out_file);
                    pos = trie_get_root(h_trie);
                }
            }
            
        }  
        
    }
    free(b);
}

