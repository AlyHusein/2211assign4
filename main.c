#include <stdio.h>
#include "bst.h"
//Aly Husein CS 2211 Assignment 4 Task 1

int main(void) {
    
    BStree newTree;
    int size;
    int newData;
    char name[256];
    int newId;
    char contQ;
    int addAnother = 1;
    
    printf("Please enter the size of your Binary Search Tree:\n ");
    scanf("%d", &size);
    //Create New Tree with given size
    newTree = bstree_ini(size);
    
    while (addAnother == 1)
    {
    
        printf("\nPlease enter the name, id and data of the node you'd like to add:\n ");
        scanf("%s %d %d", name, &newId, &newData);
        //Creates new Key
        Key *newKey = key_construct(name, newId);
        //Inserts new Node into Tree
        bstree_insert(newTree, newKey, newData);
    
        printf("\nWould you like to add another?:\n");
        printf("Type N for no\n");
        printf("Type anything else for Yes:\n");
        scanf("%s", &contQ);
        
        if (contQ == 'N') //If they put N, they'd like to quit
        {
            addAnother = 0; //Stops while function
        }
    }
    bstree_traversal(newTree);
    printf("\nThanks for using my program!, Goodbye.\n");
    bstree_free(newTree);
}
