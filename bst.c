#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned char array of size+1 for member is_free
// set all entries of is_free to 1
// set member size to ’size’;
BStree bstree_ini(int size)
{
    int i;
    BStree treePointer;
    treePointer = (BStree_struct*)malloc(sizeof(BStree_struct));
    treePointer->tree_nodes = (Node*)malloc(sizeof(Node)*(size+1));
    treePointer->is_free = (unsigned char*)malloc(sizeof(unsigned char)*(size+1));
    treePointer->size = size;
    for (i=0; i < (size+1); i++)
    {
        treePointer->is_free[i] = '1';
    }
    return treePointer;
}
// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key *key, int data)
{
    insertion_helper(bst, key, data, 1);
}

void insertion_helper(BStree bst, Key *key, int data, int index)
{
    int nodeComp;
    int leftI;
    int rightI;
    //Check if Root is there
    if (bst->is_free[1] == '1')
    {
        //Change Root variables to givens
        bst->tree_nodes[1].key = key;
        bst->tree_nodes[1].data = data;
        //Change is_free root to 0 to show it's taken
        bst->is_free[1] = '0';
    }
    else
    {
        //Compare the keys of the node with the given key, to see if right or left side
        nodeComp = key_comp(*bst->tree_nodes[index].key, *key);
        if (nodeComp > 0)//If this is true, the new key will be on the left side
        {
            leftI = lc_index(index);
            if (bst->is_free[leftI] == '1')
            {
                bst->tree_nodes[leftI].key = key;
                bst->tree_nodes[leftI].data = data;
                bst->is_free[leftI] = '0';
            }
            else
            {
                insertion_helper(bst, key, data, leftI);
            }
            
        }
        else if (nodeComp < 0)// Key will be on the right side
        {
            rightI = rc_index(index);
            if (bst->is_free[rightI] == '1')
            {
                bst->tree_nodes[rightI].key = key;
                bst->tree_nodes[rightI].data = data;
                bst->is_free[rightI] = '0';
            }
            else
            {
                insertion_helper(bst, key, data, rightI);
            }
        }
    }
}

int lc_index(int index)
{
    return index*2;
}

int rc_index(int index)
{
    return ((index*2)+1);
}


// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst)
{
    traversal_helper(bst, 1);
}

void traversal_helper(BStree bst, int index)
{
    
    if (bst->is_free[index] == '0')
    {
        traversal_helper(bst, lc_index(index));
        print_node(bst->tree_nodes[index]);
        traversal_helper(bst, rc_index(index));
    }
}

// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst)
{
    free(bst->is_free);
    free(bst->tree_nodes);
    free(bst);
}
