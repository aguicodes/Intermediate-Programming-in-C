/*  Graciela Aguilar February 9, 2016
    working with multiple files, tokenizing them 
    converting to int and processing min, max,
    mean, and sample variance*/
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void min_max(int array [], int counter, int *min, int *max);
void mean_var(int array [], int counter, double *mean, double *sample_var);

int main (int argc, char* argv[]){
/* int argc: the number of chars its taking in for array argv[] */
  
    if(argc != 3)
    {
        printf("usage: executable startInt stopInt\n");
        exit(1);
    }
  
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int i;
    
    FILE* file;
    char line[51];
    char filename[19];
    char* token, *del = "$. ";
    int cost_int = 0;
    int values[30];
    int* position = values;
    int array_counter = 0;
    int min = 0;
    int max = 0;
    double mean = 0.0;
    double variance = 0.0;
    
    for(i = start; i <= end; i++)
    {
        sprintf(filename, "hw03-data-%d.txt", i);
        if ((file = fopen(filename,"r")) == NULL)
        {
            printf("Unable to open %s file\n", filename);
            exit(1);
        }
        array_counter = 0;
        position = values;
        
        while(fgets(line, sizeof(line), file) != NULL)
        {
            token = strtok(line, del);
            while(token != NULL)
            {
                cost_int = atoi(token);
                if(cost_int != 0)
                {
                    *position = cost_int;
                    *position++;
                    array_counter++;
                }
                token = strtok(NULL, del);
            }
        }
        fclose(file);
        
        min_max (values, array_counter, &min, &max);
        mean_var(values, array_counter, &mean, &variance);
        
        printf("%-18s: min = %3d, max = %3d, mean = %6.2f, variance = %8.2f\n", filename, min, max, mean, variance);
    }
}
void min_max (int array [],int counter, int *min, int *max)
{
    int current_max = array[0];
    int current_min = array[0];
    int i;

    for(i = 0; i < counter; i++)
    {
        if(array[i] > current_max)
        {
            *max = array[i];
            current_max = array[i];
        }
        else
        {
            *max = current_max;
        }
    }
    for(i = 0; i < counter; i++)
    {
        if(array[i] < current_min)
        {
            *min = array[i];
            current_min = array[i];
        }
        else
        {
            *min = current_min;
        }
    }
}
void mean_var(int array [], int counter, double *mean, double *sample_var)
{
    double sum = 0.0;
    double var_sum = 0.0;
    int i;
    
    for(i = 0; i < counter; i++)
    {
        sum += array[i];
    }
    
    *mean = sum / counter;
    
    for (i = 0; i < counter; i++)
    {
        var_sum += ((array[i]) - *mean) * ((array[i]) - *mean);
    }
    *sample_var = var_sum / (counter-1);
}
