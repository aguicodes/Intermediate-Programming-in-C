/*  Graciela Aguilar
    March 24, 2016
    hw07 functions version
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** storeMonths(char **s);
int** createDatesArr( int **d);
void updateCounts(int*** d, char** s);
void printOutput(int **d, char **s);

int main(void){
    
    char **months;
    int **dates;
    int i = 0;
    
    months = storeMonths(months);
    
    dates = createDatesArr(dates);
    
    updateCounts(&dates, months);
    
    printOutput(dates, months);
    
    for(i = 0; i < 12; i++)
    {
        free(months[i]);
        free(dates[i]);
    }
    free(months);
    free(dates);

}
char** storeMonths(char **s)
{
    FILE* fp;
    char* filename = "months.txt";
    char text[50];
    char *tok, *del = "\n";
    int i = 0;
    
    if( (fp = fopen(filename, "r")) == NULL )
    {
        printf("unable to open %s for reading\n", filename);
        exit(1);
    }
    s = malloc(12 * (sizeof(char*)));
    
    while( fgets(text, sizeof(text), fp) != NULL )
    {
        tok = strtok(text, del);
        s[i] = malloc(strlen(text)+1);
        strcpy(s[i],text);
        i++;
    }
    fclose(fp);
    return s;
    
}

int** createDatesArr( int **d)
{
    int i = 0, j = 0;
    
    d = malloc(12 * (sizeof(int*)));
    for(i = 0; i < 12; i++)
    {
        d[i] = malloc(10 * (sizeof(int)));
    }
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 10; j++)
        {
            d[i][j] = 0;
        }
    }
    return d;
}

void updateCounts(int*** d, char** s)
{
    FILE* fp;
    char* filename = "dates.csv";
    char text[50];
    char* tok1, *tok2, *tok3,  *del = " ,\n";
    int i = 0, j = 0, counter = 0, numtok = 0;
    
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
           if(strcmp(s[i],tok1) == 0)
           {
              counter = 0;
              
              for(j = 2007; j <= 2016; j++)
              {
                  if(numtok == j)
                  {
                      (*d)[i][counter]++;
                  }
                  counter++;
              }
           }
       }
    }
    fclose(fp);
}

void printOutput(int **d, char **s)
{
    int i = 0, j = 0;

    printf("         ");
    printf("  2007  2008  2009  2010  2011  2012  2013  2014  2015  2016\n");
    
    for(i = 0; i < 12; i++)
    {
        printf("%-9s", s[i]);
        for(j = 0; j < 10; j++)
        {
            printf("%6d", d[i][j]);
        }
        printf("\n");
    }
}
