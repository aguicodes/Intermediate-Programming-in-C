/*  Graciela Aguilar,
    April 14, 2016 HW-10 
    building binary trees/printing
    to compile, type
      make
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hw10-lib.h"

int main(void)
{
    char buffer [1000];
    char *tok, *del = " \n";
    struct node *root = NULL;
    
    while(fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        tok = strtok(buffer, del);
        while(tok != NULL)
        {
            if(root == NULL)
            {
                root = addNode(tok);
                printf("add: %s\n", root->word);
                
            }
            else
            {
                insert(root, tok);
            }
            tok = strtok(NULL, del);
        }
    }
    printf("\nRESULTS\n");
    printTree(root);
    freeMem(root);
}
