/* Graciela Aguilar March 8, 2016
   HW#6 storing data from a file and 
   and using dynamic string arrays to 
   process (malloc, calloc, etc)
   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(char **s, int size);
void print_subjectTotals(char **s, int size);

int main (void){
    
    char** line_addresses, **temp;
    char line[350];
    int i = 0, size = 10;

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
    }
    printf("\n");
    
    bubble_sort(line_addresses, i);
    print_subjectTotals(line_addresses, i);
    
    for(i = 0; i < size; i++)
    {
        free(line_addresses[i]);
    }
    
    free(line_addresses);
}

void bubble_sort(char **s, int size)
{
    char *temp, *tok1, *tok2 ;
    char line1[350];
    char line2[350];
    int i, sorted;
    do {
        sorted = 1;

        for(i = 0; i < size-1; i++)
        {
            strcpy(line1, s[i]);
            tok1 = strtok(line1, ",");
            tok1 = strtok(NULL, ",");
            tok1 = strtok(NULL, ",");
            tok1 = strtok(NULL, ",");
          
            strcpy(line2, s[i+1]);
            tok2 = strtok(line2, ",");
            tok2 = strtok(NULL, ",");
            tok2 = strtok(NULL, ",");
            tok2 = strtok(NULL, ",");
 
            if(strcmp(tok1,tok2) > 0)
            {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                sorted = 0;
            }
        }
    }while( !sorted );
}
void print_subjectTotals(char **s, int size)
{   
    char line1[350];
    char line2[350];
    char *tok1, *tok2, *sub1, *sub2;
    int i = 0, value1 = 0, value2 = 0, total = 0;

    while(i < size-1)
    {

        strcpy(line1, s[i]);
        tok1 = strtok(line1, ",");
        tok1 = strtok(NULL, ",");
        tok1 = strtok(NULL, ",");
        tok1 = strtok(NULL, ",");
        sub1 = tok1;
        tok1 = strtok(NULL, ",");
        tok1 = strtok(NULL, ",");
        tok1 = strtok(NULL, ",");
        tok1 = strtok(NULL, ",");
        tok1 = strtok(NULL, ",");
        value1 = atoi(tok1);
        if(i == 0)
        {
            total = value1;
        }
  
        strcpy(line2, s[i+1]);
        tok2 = strtok(line2, ",");
        tok2 = strtok(NULL, ",");
        tok2 = strtok(NULL, ",");
        tok2 = strtok(NULL, ",");
        sub2 = tok2;
        tok2 = strtok(NULL, ",");
        tok2 = strtok(NULL, ",");
        tok2 = strtok(NULL, ",");
        tok2 = strtok(NULL, ",");
        tok2 = strtok(NULL, ",");
        value2 = atoi(tok2);
 
        if((strcmp(sub1,sub2)) == 0)
        {
          total += value2;
        }
        else
        {
            printf("%-9s%6d\n", sub1, total);
            total = value2;
        }
        i++;
        if(i == size - 1)
        {
            printf("%-9s%6d\n", sub2, total);
        }
    }
}
