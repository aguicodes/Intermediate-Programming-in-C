/*
    this file should include function definitions

    include any libraries needed by your functions
*/
#include <stdio.h>
#include "hw10-lib.h"
#include <string.h>
#include <stdlib.h>

struct node *addNode (char *s)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->word = malloc(strlen(s) + 1);
    strcpy(temp->word, s);
    temp->count = 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insert(struct node *root, char *s)
{
    if(strcmp(s,root->word) < 0)
    {
        if(root->left == NULL)
        {
            root->left = addNode( s );
            printf("left add: %s\n", s);
        }
        else
        {
            printf("going left\n");
            insert( root->left, s );
        }
    }
    else if(strcmp(s,root->word) > 0)
    {
        if(root->right == NULL)
        {
            root->right = addNode( s );
            printf("right add: %s\n", s);
        }
        else
        {
            printf("going right\n");
            insert( root->right, s);
           
        }
    }
    else if((strcmp(s,root->word)) == 0)
    {
        root->count = root->count + 1;
        printf("updating count: %s\n", root->word);
    }
}
void printTree(struct node *root)
{
    if(root == NULL)
    return;

    printTree(root->left);
    printf("%s, %d\n", root->word, root->count);
    printTree(root->right);
}
void freeMem(struct node *root)
{
    if(root == NULL)
        return;

    freeMem(root->left);
    freeMem(root->right);
    free(root->word);
    free(root);
}
