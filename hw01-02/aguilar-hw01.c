/* Graciela Aguilar January 27, 2016
   homework #1*/

#include <stdio.h>
#include <stdlib.h>

int main (void){

    double value;
    int i;
    int j;
    double sum;
    double average;
    double counter;
    
    
    for(i = 0; i < 10; i++)
    {   
        counter = 0.0;
        sum = 0.0;
        for(j = 0; j < 4; j++)
        {
            value = (rand()%10000) / 100.0;
            
            if(value >= 67.0)
            {
                sum += value;
                counter ++;
                printf("%5.2f  ", value);
                
            }
            else
            {
                printf("       ");
            }
        }
        
        if(sum == 0.0)
        {
            printf("|\n");
        }
        else
        {
            average = sum / counter;
            printf("|  %5.2f\n", average);
        }
    }
}


