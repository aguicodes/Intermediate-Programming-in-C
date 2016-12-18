/* Graciela Aguilar
     April 27, 2016 hw-12 */
     
#include <stdio.h>
#include <glob.h>
#include <string.h>
#include <stdlib.h>

struct list{
    int course;
    int year;
    int enrollCounts [14];
};
void openFilesBuildStruct(char *filename, struct list **s, int *count, int *size);
int addProperCounter(int month, int day);

int main(void)
{
    glob_t  paths;  
    int csource, structCounter = 0;
    char **p;
    struct list *enrollments;
    int size = 5;
    int j = 0, i = 0;
    
    enrollments = malloc(size * sizeof(struct list));
    
    
    
     
    /*  Find all ".csv" files in given directory  */
    csource = glob("*.csv", 0, NULL, &paths);
     
    if (csource == 0)
    {
        for (p=paths.gl_pathv; *p != NULL; ++p)
        {
            openFilesBuildStruct(*p, &enrollments, &structCounter, &size);  
        }
        globfree(&paths); 
    }
    
    for(i = 0; i < structCounter; i++)
    {
        printf("%d, %d,", enrollments[i].course, enrollments[i].year);
        for(j = 0; j < 14; j++)
        {
            printf("%d,", enrollments[i].enrollCounts[j]);
        }
    }
    free(enrollments);
}
void openFilesBuildStruct(char *filename, struct list **s, int *count, int *size)
{
    FILE *fp;
    char buffer[301];
    char file[50];
    char date[50];
    int course = 0, year = 0;
    static int counter = 0;
    char *tok, *last, *del = "-cse.";
    int month = 0, day = 0, i = 0, j = 0;
    int found = 0, position = 0;
    
    strcpy(file, filename);
    tok = strtok(file, del);
    year = atoi(tok);
    tok = strtok(NULL, del);
    course = atoi(tok);
    counter++;
    
    if(counter < (*count)+1)
    {
        (*size) = (*size) + 5; 
        *s = realloc(*s, (*size) * sizeof(struct list));
    }
    
    
    for(j = 0; j < (*count); j++)
    {
        if(((*s)[j].year == year) && ((*s)[i].course == course))
        {
            found = 1;
            position = j;
        }
    }
    
    if (found == 0)
    {
        (*s)[*count].year = year;
        (*s)[*count].course = course;
        (*count)++;
    }
  
    
    if( (fp = fopen(filename, "r")) == NULL )
    {
        printf("unable to open %s\n", file);
        exit(1);
    }
    
    fgets(buffer, sizeof(buffer), fp);
    while( fgets(buffer, sizeof(buffer), fp) != NULL )
    {
        tok = strtok(buffer, ",\n");
        while(tok != NULL)
        {
            last = tok;
            tok = strtok(NULL, ",\n");
        }
        strcpy(date, last);
        
        tok = strtok(date, "/");
        month = atoi(tok);
        tok = strtok(NULL, "/");
        day = atoi(tok);
        
        /*printf("month = %d, day = %d, counter = %d\n", month, day, counter);*/
        i = addProperCounter(month, day);
        if(found == 0)
        {
            (*s)[*count].enrollCounts[i]++; 
        }
        else
        {
            (*s)[position].enrollCounts[i]++;
        }
        found = 0; 
            
    }
    
    
    fclose(fp);
}
int addProperCounter(int month, int day)
{
    if(day > 24)
    {
        if(month > 8)
        {
            return 13;
        }
    }
    if((month == 6) && (day ==1))
    {
        return 0;
    }
    if(month < 6)
    {
        return 0;
    }
    if((month <= 6) && (day <= 8))
    {
        return 1;
    }
    if((month <= 6) && (day <= 15))
    {
        return 2;
    }
    if((month <= 6) && (day <= 22))
    {
        return 3;
    }
    if((month <= 6) && (day <= 29))
    {
        return 4;
    }
    if((month <= 7) && (day <= 6))
    {
        return 5;
    }
    if((month <= 7) && (day <= 13))
    {
        return 6;
    }
    if((month <= 7) && (day <= 20))
    {
        return 7;
    }
    if((month <= 7) && (day <= 27))
    {
        return 8;
    }
    if((month <= 8) && (day <= 3))
    {
        return 9;
    }
    if((month <= 8) && (day <= 10))
    {
        return 10;
    }
    if((month <= 8) && (day <= 17))
    {
        return 11;
    }
    if((month <= 8) && (day <= 24))
    {
        return 12;
    }
    
}
