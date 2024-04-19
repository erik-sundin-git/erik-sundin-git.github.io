/**
 * @defgroup freq_table_h Frequency table
 * 
 * @brief A datatype used for creating frequencytables of characters in a textfile.
 *        
 *       All textdata in this datatype uses unicode UTF-8 encoding.
 * 
 * @author: Erik Sundin <dv22esn@cs.umu.se>
 * @since: 2022-02-07
 * 
 * @{
*/

#ifndef FREQ_TABLE_H
#define FREQ_TABLE_H

#define MAX_CAPACITY 256

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief         function for creating a frequencytable from a textfile
 *          
 *                Creates and fills a dynamically allocated freq_table.
 *                The first 256 unicode characters are represented as the index 
 *                of the array. The value at each index is the frequency of that character.
 *                
 *                The table is dynamically allocated and must be freed by the user.
 * 
 * @param  file   File pointer to the file being read.
 * @return int*   The created table.
 */
int *freq_table_create(FILE *file);



/* ****** Utility functions ********** */

/*
 * @brief utility function for printing all elements with a value in a frequency table
 *   
 * @param table to be printed.
 * @return -
 */
void freq_table_print(int *table);




/**
 * @}
 */
#endif