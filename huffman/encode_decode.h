#if !defined(ENCODE_DECODE_H)
#define ENCODE_DECODE_H

#include "htable.h"
#include "bit_buffer.h"


/**
 * 
 * @defgroup encode_decode
 * @brief A module for handling encoding and decoding text using huffman enoding.
 * 
 *       Use text_encode to encode a file
 *       Use text_decode to decode.   
 * 
 * @{ 
 */



/**
 * @brief          Encodes text using huffman codes.
 *                  
 *                 Encodes the input file using huffman coding. Writes the encoded text to the outfile.
 *                 The input file is encoded using the huffman table given as parameter.
 *                 The same huffman table must be used when decoding the text later.
 * 
 * @param in_file  File to encode. 
 * @param out_file File to write encoded text to.
 * @param tb       Huffman table to get the huffman code from.
 * @return -
 * 
 */
void text_encode(FILE *in_file, FILE *out_file, htable *tb);



/**
 * @brief          Decodes huffman encoded text.  
 *
 *                 Decodes the input file and writes the decoded text to the output file.
 *                 The huffman trie must be the same used to build the huffman table
 *                 in text_encode. 
 * 
 * @see text_encode
 * @param in_file  File to be decoded.
 * @param out_file File to write the decoded text to.
 * @param h_trie   huffman trie used for decoding.
 * @return -
 */
void text_decode(FILE *in_file, FILE *out_file, trie *h_trie);




/**
 * TODO: ta bort innan inlämning
 */
void text_decode_gam(FILE *in_file, FILE *out_file, trie *h_trie);



/**
 * @}
*/

#endif // ENCODE_DECODE_H
