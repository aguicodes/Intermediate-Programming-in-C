/* Graciela Aguilar March 3, 2016
   HW#6 storing data from a file and 
   and using dynamic string arrays to 
   process (malloc, calloc, etc)
   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void bubble_sort(char **s, int size);*/

int main (void){
    
    char** line_addresses, **temp;
    char line[349];
    int j, i = 0, size = 10;

    line_addresses = malloc (size * sizeof(char*));
    
    fgets(line, sizeof(line), stdin);
    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        if((i+1) > size)
        {
            if((temp = realloc(line_addresses, 2 * (size * sizeof(char*)))) != NULL)
            {
                line_addresses = temp;
            }
            else
            {
                printf("Unable to reallocate\n Exiting...\n");
                exit(1);
            }
            size = 2 * size;
            printf("reallocating to %d\n", size);
        }
        line_addresses[i] = malloc(strlen(line) + 1);
        strcpy(line_addresses[i], line);
        i++;
        /*printf("counter = %d ", i+1);*/
    }
  
    /*printf("number of loops = %d\n", i);
    for(j = 0; j < i; j++)
    {
        printf("line_addresses[%d] = %s\n", j, line_addresses[j]);
    }*/
}
/*void bubble_sort(char **s, int size)
{
    int i, temp, sorted;

    do {
        sorted = 1;

        for(i = 0; i < size-1; i++)
            if(d[i] > d[i+1])
            {
                temp = d[i];
                d[i] = d[i+1];
                d[i+1] = temp;
                sorted = 0;
            }
    }while( !sorted );
}*/
