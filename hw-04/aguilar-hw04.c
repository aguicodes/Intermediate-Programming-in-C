
/* use -lm  ex. gcc -lm... for pow function 
  Graciela Aguilar february 15, 2016
    homework #4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void process_base(char* s []);
void process_minbits(char* s []);
int num_of_bits(unsigned int num);
void base_2(int num);

int main(void){

    int i = 0, j = 0;
    char buffer[100];
    char* token, *del = " ,\n";
    char* base_conv_tokens [6];
    char* min_bits_tokens [6];


    while ((fgets(buffer, sizeof(buffer), stdin)) != NULL){
        
        j = 0;
        i = 0;
        
        token = strtok(buffer, del);
        if (token[0] == 'b')
        {
            while(token != NULL)
            {
                base_conv_tokens[i] = token;
                i++;
                token = strtok(NULL, del);
            }
            process_base(base_conv_tokens);  
        }
        
        else
        {
            while(token != NULL)
            {
                min_bits_tokens[j] = token;
                j++;
                token = strtok(NULL, del);
            }
            process_minbits(min_bits_tokens);
        }
    }
}

void process_base(char* s [])
{
    int base_start = atoi(s[2]);
    int base_end = atoi(s[3]);
    int length = strlen(s[4]);
    /* the length variable is the length of the last token, i use to to indentify the 
       length of the binary number for array looping purposes */
    unsigned long int result = 0;
    
    if (base_start == base_end)
    {
        printf("%s in base-%d is %s in base-%d\n", s[4], base_start, s[4], base_end);
    }
    else if (base_start == 10)
    {
        printf("%s in base-%d is ", s[4], base_start);
        base_2(atoi(s[4]));
        printf(" in base-%d\n", base_end);
    }
    else
    {
        
        char b [64];
        int i;
        int j = 0; 
        int k = length - 1;
        
        strcpy(b, s[4]);
 
        for(i = 0; i < length; i ++)
        {
            j = (int)(b[i] - '0');
            
            result += j * (pow(2, k));
            k--;
            
        }
        printf("%s in base-%d is %lu in base-%d\n", s[4], base_start, result, base_end);
    }
    
}

void process_minbits(char* s [])
{
    char int_type [10];
    unsigned int num = atoi(s[3]);
    int result = num_of_bits(num);
    strcpy(int_type, s[2]);
    
    
      if((int_type[0]) == 's')
      {
          printf("it takes a minimum of %d bits to represent %d as a signed int\n", (result + 1), num );
          
      }
      else
      {
          printf("it takes a minimum of %d bits to represent %d as an unsigned int\n", result, num );
      }
}

void base_2(int num)
{
    int i = num, j = 0;
    int binary_number [64];
    
    while(i != 0)
    {
        binary_number[j] = (i % 2);
        i = i / 2;
        j++;
    }
    
    for(j-- ; j >= 0; j--)
    {
        printf("%d", binary_number[j]);
    }
}
int num_of_bits(unsigned int num)
{
    unsigned int i = num;
    int j = 0;
        while(i != 0)
        {
            i = i / 2;
            j++;
        }
            
        return j;
}
