#include <stdio.h>
#include "data.h"

typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;

typedef BStree_struct* BStree;

BStree bstree_ini(int size);

void bstree_insert(BStree bst, Key *key, int data);

void insertion_helper(BStree bst, Key *key, int data, int index);

void bstree_traversal(BStree bst);

void traversal_helper(BStree bst, int index);

void bstree_free(BStree bst);

int lc_index(int index);

int rc_index(int index);
