#if !defined(HTABLE_H)
#define HTABLE_H


#include "trie.h"
#include <string.h>



/**
 * @defgroup Htable
 * @brief Module used for creating huffman codes from a huffman trie.
 *
 *        The huffman codes are stored as strings in a huffman table
 *        @see htable. The htables are dynamically allocated and must be
 *        freed using htable_kill.
 *        @see htable_kill.
 * @{
 */



/**
 * @brief   The type for a table.
 * 
 * @element table An array of strings for storing huffman codes.
 */
typedef struct htable htable;



/**
 * @brief             Get the huffman code for the character given as parameter.
 * 
 * @param  table      Table to find the code in.
 * @param  character  Character to get the code for.
 * @return char*      The code stored as a string.
 */
char *htable_get_code(htable *table, int character);



/**
 * @brief  Fills huffman table with codes using the huffman trie.
 * 
 *         Must be called with an index of zero and a dynamically
 *         Allocated string path. The parameter index is used for
 *         positioning within the trie.
 * 
 * @param  trie_root The rootnode of the huffman trie.
 * @param  tb Huffman table to fill
 * @param  index Index used for positioning
 * @return -
 */
void htable_fill(q_node *trie_root, htable *tb, int index, char *path);



/**
 * @brief  Creates an empty huffman table.
 * 
 *         The table is dynamically allocated and it's
 *         the responsibility of the caller to deallocate.
 *         Can be done using htable_kill
 *         @see htable_kill
 * 
 * @param  -
 * @return htable The created htable.
 */
htable *htable_empty();



/**
 * @brief  Deallocates memory occupied by a huffman table.
 * 
 * @param  table huffman table to be killed.
 * @return -
 */
void htable_kill(htable *table);



/**** Utility functions ****/



/*
 * Prints information related to the huffman table.
 */
void print_htable(htable *table, int *freq_table);



/**
 *@} 
*/



#endif // HTABLE_H
