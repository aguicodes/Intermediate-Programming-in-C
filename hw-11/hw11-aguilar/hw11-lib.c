#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw11-lib.h"

void expandStruct ( struct curriculum **s, int *size)
{
    *size = *size + 5;
    *s = realloc(*s, (*size) * sizeof(struct curriculum));
}
struct curriculum *createRqmtList (char *file, int *counter)
{
    FILE *fp;
    char buffer[350];
    int memSize = 5;
    struct curriculum *s;
    char *tok, *del = ",\n";
    
    s = malloc( memSize * sizeof(struct curriculum) );
    
    if( (fp = fopen(file, "r")) == NULL )
    {
        printf("unable to open %s\n", file);
        exit(1);
    }

    while( fgets(buffer, sizeof(buffer), fp) != NULL )
    {
        if (((*counter)+1) > memSize)
        {
           expandStruct(&s, &memSize); 
        }
        if(buffer[0] == '#')
        {
            
            continue;
        }
        else
        {
            tok = strtok(buffer, del);
            s[*counter].courseName = malloc(strlen(tok) + 1);
            strcpy((s[*counter].courseName), tok);
            
            tok = strtok(NULL, del);
            s[*counter].category = malloc(strlen(tok) + 1);
            strcpy((s[*counter].category), tok);
            
            tok = strtok(NULL, del);
            s[*counter].preQ = malloc(strlen(tok) + 1);
            strcpy((s[*counter].preQ), tok);
            
            tok = strtok(NULL, del);
            s[*counter].notes = malloc(strlen(tok) + 1);
            strcpy((s[*counter].notes), tok);
            
            *counter = *counter + 1;
        }
    }
    fclose(fp);
    
    return (s);
}
char** createCourseWorkArr(char *file, int *counter)
{
    FILE *fp;
    char buffer[50];
    char **s;
    int size = 5;
    
    s = malloc(size *sizeof(char*));
    
    if( (fp = fopen(file, "r")) == NULL )
    {
        printf("unable to open %s\n", file);
        exit(1);
    }

    while( fgets(buffer, sizeof(buffer), fp) != NULL )
    {
        if(((*counter)+1) > size)
        {
            size = size + 5;
            s = realloc(s, (size * sizeof(char*)));
        }
        strtok(buffer, "\n");
        s[*counter] = malloc(strlen((buffer) + 1));
        strcpy(s[*counter], buffer);
        *counter = *counter + 1;
    }
    fclose(fp);
    return (s);
    
}
void printOutput(struct curriculum *s1, char **s2, int s1Count, int s2Count)
{
    int i = 0, j = 0, found = 0, pre = 0;
    char *str1, *str2;
    
    printf("COURSES ELIGIBLE TO TAKE\n------------------------\n");
    
    for(i = 0; i < s1Count; i++)
    {
        found = 0;
        pre = 0;
        str1 = s1[i].courseName;
        
        for(j = 0; j < s2Count; j++)
        {
            str2 = s2[j];
            if(strcmp(str1, str2) == 0)
            {
                found = 1;
            }
        }
        pre = preReqs(s2, s1[i].preQ, s2Count);
        if((found == 0) && (pre == 0))
        {
            printf("  %s", str1);
            if(strcmp((s1[i].notes), "none") != 0)
            {
                printf(" (%s)\n", s1[i].notes);
            }
            else
            {
                printf("\n");
            }
        }
    }
}
int preReqs(char **s1, char *s2, int count)
{
    char *tok;
    int i = 0, found = 0;
    char s[50];
    
    
    if (strcmp(s2, "none") == 0)
    {
        return 0;
    }
    else 
    {
        strcpy(s, s2);
        tok = strtok(s,"|");
        while(tok != NULL)
        {
            if (found == 1)
            {
                return 1;
            }
            found = 1;
            for(i = 0; i < count; i++)
            {
                if(strcmp(tok,s1[i]) == 0)
                {
                    found = 0;
                }
            }
            tok = strtok(NULL, "|");
        }
    }
    return found;
}
void freeStruct(struct curriculum *s, int counter)
{
    int i = 0;
    
    for(i = 0; i < counter; i++)
    {
        free(s[i].courseName);
        free(s[i].category);
        free(s[i].preQ);
        free(s[i].notes);
    }
    free(s);
}
void freeArray(char **s, int count)
{
    int i = 0;
    
    for(i = 0; i < count; i++)
    {
        free(s[i]);
    }
    free(s);
}
