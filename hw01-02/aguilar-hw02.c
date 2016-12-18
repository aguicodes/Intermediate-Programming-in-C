/* Graciela Aguilar February 3, 2016
homework #2 - pointers */

#include <stdio.h>
#include <stdlib.h>

void fx1 (int array [] [5], int rows, int* colIndex, int* maxSum);
void fx2 (int array [] [5], int rows, int colIndex, double* mean, double* var);
void fx3 (int array [] [5], int rows);

int main(void){

    int array1 [] [5]  = {{-55, -8, -12, -6, -1},{-10, -4, -7, -5, -6},
                         {-20, -3, -15, -4, -2}};
                         
    int array2 [] [5] = {{1, 14, -6, -2, 5},{0, 12, -4, 3, -5},{2, 12, -4, 5, -6},
                         {4, 16, -7, 15, 4},{3, 17, -9, 4, 0}};
    
    int posOfCol = 0, max = 0;
    double mean = 0.0, samVar = 0.0;
    
    int row1 = sizeof(array1)/ sizeof(array1[0]);
    int row2 = sizeof(array2)/ sizeof(array2[0]);
    
    printf("The array\n\n");
    fx3(array1,row1);
    printf("\n");
    fx1(array1, row1, &posOfCol, &max);
    fx2(array1, row1, posOfCol, &mean, &samVar);
    printf("has a maximum sum of %d in the column with index %d.\n", max, posOfCol);
    printf("This column has a mean of %.3f and a variance of %.3f.\n\n", mean, samVar);
    
    printf("The array\n\n");
    fx3(array2,row2);
    printf("\n");
    fx1(array2, row2, &posOfCol, &max);
    fx2(array2, row2, posOfCol, &mean, &samVar);
    printf("has a maximum sum of %d in the column with index %d.\n", max, posOfCol);
    printf("This column has a mean of %.3f and a variance of %.3f.\n\n", mean, samVar);
    
    
    
    
}

void fx1 (int array [][5], int rows, int* colIndex, int* maxSum)
{
    int i, j;
    int counter = 0;
    int current_sum = 0;
    *colIndex = 0;
    
    for(i = 0; i < rows; i++)
    {
       counter = array [i][0];
       *maxSum += counter;
    }

    for(i = 1; i < 5; i++)
    {
        counter = 0;
        current_sum = 0;
        
        for(j = 0; j < rows; j++)
        {
            counter = array [j][i];
            current_sum += counter;
        }
        
        if(*maxSum < current_sum)
        {
            *maxSum = current_sum;
            *colIndex = i;
        }
    }
}

void fx2 (int array [][5], int rows, int colIndex, double* mean, double* var)
{
    double sum = 0.0, sum2 = 0.0, value = 0.0;
    int i;
    
    for(i = 0; i < rows; i++)
    {
        value = array [i][colIndex];
        sum += value;
    }
    
    *mean = sum / rows;
    
    for(i = 0; i < rows; i++)
    {
        value = array [i][colIndex] - *mean;
        
        sum2 += value * value;
        
    }
    
    *var = sum2 / (rows-1);
}

void fx3 (int array [] [5], int rows)
{
    int b, c;
    
    for(b = 0; b < rows; b++)
    {
        for(c = 0; c < 5; c++)
        { 
            if(c == 4)
            {
                printf("%4d", array [b][c]);
            }
            else
            {
                printf("%4d,", array [b][c]);
            }
            
        }
        printf("\n");
    }
}


