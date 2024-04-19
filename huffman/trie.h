#ifndef TRIE_H
#define TRIE_H

#include "freq_table.h"
#include "pqueue.h"
#include "list.h"

/**
 * @defgroup trie
 * @brief A datatype used for creating a huffman trie.
 * 
 *        Operations intended for use when creating a huffman trie.
 *        The datatype uses a frequency table of type int* as input
 *        aswell as a priority queue.
 *        @see pqueue.h
 * 
 *        A trie is dynamically allocated and must be ddeallocated by the user
 *        Can be done using trie_destroy
 *        @see trie_destroy
 * 
 * @{ 
 */



/**
 * @brief The typ for queue node 
 * 
 * @elem  prio the priority of the node. Type int
 * @elem  val the character stored in the node. Type unsigned int.
 * @elem  is_leaf boolean value for storing wether the node is a leaf or not.
 * 
 * @elem  left_child, right_child the nodes children.
 * 
 *        If the node has no children is_leaf is set to true.
 *        A node is created using trie_create_node.
 * @see   trie_create_node
 * 
 *        A node is dynamically allocated and must be deallocated by the user to avoid memory leaks.
 *        This can be done using trie_destroy_q_node
 * @see   trie_destroy_q_node.
 * 
 * TODO:
 */
typedef struct q_node q_node;



/**
 * @brief The type for a trie.
 *        
 *        Can be created using trie_create_trie.
 *        Memory for a trie is dynamically allocated 
 *        and can be freed by trie_destroy.
 * 
 * @see   trie_create_trie
 * @see   trie_destroy
 *          
 * @elem  root Pointer to the root of the trie. 
 */
typedef struct trie trie;



/**
 * TODO:
 * @brief Creates a priority queue from the frequency table.
 *        
 *        The table is created using the frequency table given.
 *        If the queue is to be created containing all characters
 *        in the frequency table the parameter size must be the
 *        same size as the frequency table.
 * 
 * @param table Frequency table of UTF-8 characters.
 * @param size  size of the pqueue. 
 */
pqueue *trie_create_pq(int *table, int size);



/**
 * @brief Create a new huffman trie from frequency table.
 *        The datatype expects a table of size 256. Behaviour of of the function
 *        with any other size is undefined and will probably not work.
 * 
 *        A trie is dynamically allocated and must be freed by the user.
 *        Can be done using trie_destroy
 *        @see trie_destroy
 * 
 * 
 * @param freq_table frequency table of UTF-8 characters.
 * @param pq         Priority que used for creating the trie.
 * @return trie*     Pointer to the created trie. 
 */
trie *trie_create_trie(int *freq_table, pqueue *pq);



/**
 * @brief frees the memory used by a trie.
 * 
 * @param to_destroy Trie being destroyed.
 * @param root       rootnode of the trie being destroyed.
 * @return - 
 */
void trie_destroy(trie *to_destroy, q_node *root);



/**
 * @brief   Creates an empty queue node.
 *       
 *          A node is dynamically allocated an can
 *          be freed using trie_destroy_q_node
 *          @see trie_destroy_q_node
 * @param   -
 * @return  q_node* pointer to the created queuenode.
 */
q_node *trie_create_node();



/**
 * @brief   returns the root of the trie given as parameter.
 * 
 * @param t Trie to get the root of.
 * @return  q_node* queuenode that is the root of the trie.
 */
q_node *trie_get_root(trie *t);



/**
 * @brief Check if node is a leafnode
 * 
 * @param node To check
 * @return boolean
 */
bool trie_node_is_leaf(q_node *node);



/** 
 * @brief Get the left child of the node
 * 
 * @param node To get left child of.
 * @return     q_node* Pointer to the left child. 
 */
q_node *trie_node_left_child(q_node *node);



/** 
 * @brief Get the right child of the node
 * 
 * @param node To get right child of.
 * @return     q_node* Pointer to the right child. 
 */
q_node *trie_node_right_child(q_node *node);



/**
 * @brief Get the value of the node.
 * 
 * @param node To get value from.
 * @return int Value of the node.
 */
int trie_node_get_value(q_node *node);



/**
 * @brief Set the value of the node.
 * 
 * @param n   Node to set the value of.
 * @param val Value to set.
 * @return    -  
 */
void trie_node_set_value(q_node *n, int val);

/**
 * @brief Set the prio of the node.
 * 
 * @param n    Node to set the prio of.
 * @param prio Prio to set.
 * @return     -
 */
void trie_node_set_prio(q_node *n, int prio);

/**
 * @brief Frees the memory occupied by a queue node.
 * 
 * @param node to free.
 * @return     -
 */
void trie_destroy_q_node(q_node *node);


/****  Utility functions ****/


/*
 * Function for printing information related to
 * a priority que node.
 */
void q_node_print(q_node *node);



/**
 * @}
 */


#endif