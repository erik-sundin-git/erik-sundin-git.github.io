#include "trie.h"



#define QUEUE_CAP 256
#define TRIE_MAX_SIZE 1500


typedef struct q_node {
	int prio;
	unsigned int val;
    bool is_leaf;

    struct q_node *left_child;
    struct q_node *right_child; 
} q_node;



typedef struct trie { 
    q_node *root;
} trie;



/*** Internal functions ***/


void q_node_print(q_node *node) {
    printf("Val: %d\n", node->val);
    printf("leaf: %d\n", node->is_leaf);
    printf("prio: %d\n", node->prio);
    printf("Val: %c\n", node->val);
    printf("Left child: %p\n", node->left_child);
    printf("right child: %p\n", node->right_child);
    printf("\n\n");
}



static int lessthan(void *node1, void *node2) {
	return ((q_node *)node1)->prio - ((q_node *)node2)->prio;
}



/********   External functions   ********/



pqueue *trie_create_pq(int *table, int size) {
    q_node *node;
    pqueue *pq;

    pq = pqueue_empty(lessthan);

    for (int i = 0; i < size; i++) {
        node = trie_create_node();
        node->prio = table[i];
        node->val = i;
        pqueue_insert(pq, node);
    }
    return pq;
}



trie *trie_create_trie(int *freq_table, pqueue *pq) {
    
    //allocate trie
    trie *h_trie = malloc(sizeof(trie));
    q_node *new;
    q_node *n1;
    q_node *n2;

    while (!(pqueue_is_empty(pq))){
        // save the two nodes with least prio from the qeueu and remove them from the queue
        n1 = pqueue_inspect_first(pq);
        pqueue_delete_first(pq);

        

        n2 = pqueue_inspect_first(pq);
        pqueue_delete_first(pq);
        
        // Create a new node with no char value and the childrens combined priority.
        new = trie_create_node();
        new->prio = n1->prio + n2->prio;
        new->is_leaf = false;

        // add the children to the new nodes left and right childpointers.
        new->left_child = n1;
        new->right_child = n2;
        //Insert the new node into to the priority queue.
        if(!(pqueue_is_empty(pq))) {
            pqueue_insert(pq, new);
        }
    }
    //insert the remaining node into the trie.
    
    h_trie->root = new;
    return h_trie;
}



q_node *trie_get_root(trie *t) {
    return t->root;
}



void trie_destroy(trie *to_destroy, q_node *root) {
    trie_destroy_q_node(to_destroy->root);
    free(to_destroy);
}



q_node *trie_create_node() {
    q_node *node = malloc(sizeof(q_node));
    if (node == NULL){
        fprintf(stderr, "Error allocating q_node ");
    }
    node->is_leaf = true;
    node->left_child = NULL;
    node->right_child = NULL;

    return node;
}



bool trie_node_is_leaf(q_node *node) {
    return node->is_leaf;
}



q_node *trie_node_left_child(q_node *node) {
    return node->left_child;
}



q_node *trie_node_right_child(q_node *node) {
    return node->right_child;
}



int trie_node_get_value(q_node *node) {
    return node->val;
}



void trie_node_set_value(q_node *n, int val) {
    n->val = val;
}



void trie_node_set_prio(q_node *n, int prio) {
    n->prio = prio;
}


void trie_destroy_q_node(q_node *node) {
     if (node->left_child != NULL){
        trie_destroy_q_node(node->left_child);
    } if (node->right_child != NULL) {
        trie_destroy_q_node(node->right_child);
    }
    free(node);
}

