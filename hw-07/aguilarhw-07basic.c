/* Graciela Aguilar
   March 16, 2016 hw#07*/
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    
    FILE* fp;
    char **months;
    int **date_counts;
    char text[50];
    char* tok1, *tok2, *tok3,  *del = " ,\n", *del1 = "\n";
    char* filename = "months.txt";
    int i = 0, j = 0, counter = 0, numtok = 0;

    if( (fp = fopen(filename, "r")) == NULL )
    {
        printf("unable to open %s for reading\n", filename);
        exit(1);
    }
    months = malloc(12 * (sizeof(char*)));
    
    while( fgets(text, sizeof(text), fp) != NULL )
    {
        tok1 = strtok(text, del1);
        months[i] = malloc(strlen(text)+1);
        strcpy(months[i],text);
        i++;
    }
    fclose(fp);
    
    date_counts = malloc(12 * (sizeof(int*)));
    for(i = 0; i < 12; i++)
    {
        date_counts[i] = malloc(10 * (sizeof(int)));
    }
    printf("           2007  2008  2009  2010  2011  2012  2013  2014  2015  2016\n");
                    
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 10; j++)
        {
            date_counts[i][j] = 0;
        }
    }
    
    filename = "dates.csv";
    if( (fp = fopen(filename, "r")) == NULL )
    {
        printf("unable to open %s for reading\n", filename);
        exit(1);
    }
    while( fgets(text, sizeof(text), fp) != NULL )
    {
       tok1 = strtok(text, del);
       tok2 = strtok(NULL, del);
       tok3 = strtok(NULL, del);
       numtok = atoi(tok3);
       
       for(i = 0; i < 12; i++)
       {
           if(strcmp(months[i],tok1) == 0)
           {
              counter = 0;
              
              for(j = 2007; j <= 2016; j++)
              {
                  if(numtok == j)
                  {
                      date_counts[i][counter]++;
                  }
                  counter++;
              }
           }
       }
    }
    fclose(fp);
    
    for(i = 0; i < 12; i++)
    {
        printf("%-9s", months[i]);
        for(j = 0; j < 10; j++)
        {
            printf("%6d", date_counts[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 12; i++)
    {
        free(months[i]);
        free(date_counts[i]);
    }
    free(months);
    free(date_counts);
}
