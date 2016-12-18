/* Graciela Aguilar Feb 26, 2016
   Homework #5
   reads a csv file and processes preferred subject and it's details(only specific 
   columns) into a structure. 
   also sorts the structure in ascending order by catalog #.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct course_summary{
    
    int catalog_number;
    int sections;
    int enrollment_total;
};

void bubble_sort(struct course_summary s[], int size);
void overall_totals(struct course_summary s[], int size);

int main(void){
    
    char buffer [349];
    int skip_firstln = 0, stru_count = 0, i = 0, found = 0;
    char* tok, *del = ",";
    struct course_summary cse[100];
    char* storage [3];
    char b [10];
    
    while ((fgets(buffer, sizeof(buffer), stdin)) != NULL){
        found = 0;
        
        if(skip_firstln == 0)
        {
            skip_firstln = 1;
            continue;
        }
        tok = strtok(buffer, del);
        tok = strtok(NULL, del);
        tok = strtok(NULL, del);
        tok = strtok(NULL, del);
        storage[0] = tok;
        strcpy(b, storage[0]);
        if(strcmp(b, "CSE") == 0)
        {
            tok = strtok(NULL, del);
            storage[1] = tok;
            tok = strtok(NULL, del);
            tok = strtok(NULL, del);
            tok = strtok(NULL, del);
            tok = strtok(NULL, del);
            storage[2] = tok;

            if(stru_count > 0){
                for(i = 0; i < stru_count; i++)
                {
                    if(cse[i].catalog_number == (atoi(storage[1])))
                    {
                        cse[i].sections += 1;
                        cse[i].enrollment_total += (atoi(storage[2]));
                        found = 1;
                    }
                }
            }
            if((stru_count == 0) || (found == 0)){
                cse[stru_count].enrollment_total = (atoi(storage[2]));
                cse[stru_count].sections = 1;
                cse[stru_count].catalog_number = (atoi(storage[1]));
                stru_count++;
            }
        }
    }
    
   bubble_sort(cse, stru_count);
   
   for(i = 0; i < stru_count; i++)
    {
        if((cse[i].sections) == 1)
        {
            printf("CSE %d has %2d section  with a combined enrollment of %3d\n"
                   , cse[i].catalog_number, cse[i].sections, cse[i].enrollment_total);
        }
        else
        {
            printf("CSE %d has %2d sections with a combined enrollment of %3d\n"
                   , cse[i].catalog_number, cse[i].sections, cse[i].enrollment_total);
        }
    }
    
   overall_totals(cse, stru_count);
}

void bubble_sort(struct course_summary s[], int size)
{
    int i, sorted;
    struct course_summary temp;

    do {
        sorted = 1;

        for(i = 0; i < size-1; i++)
            if(s[i].catalog_number > s[i+1].catalog_number)
            {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
                sorted = 0;
            }
    }while( !sorted );
}
void overall_totals(struct course_summary s[], int size)
{
    int sections = 0, enrollments = 0, i;
    
    for(i = 0; i < size; i++)
    {
        sections += s[i].sections;
        enrollments += s[i].enrollment_total;
    }
    
    printf("\nTotals:  %d courses, %d sections, %d combined enrollment\n", size, sections, enrollments);
}
