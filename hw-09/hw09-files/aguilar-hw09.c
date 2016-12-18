#include <stdio.h>
#include <glob.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int x;
    char* string2;
    struct node *next;
};

struct node* addNode(char s[], int num);
void printList(struct node* head);
void freeList(struct node* head);
void editDistance( char *str1, char *str2, int *result);

int main (int argc, char* argv[]){
    char pathname[10];
    glob_t paths;  
    int csource;
    char **p;
    int j = 1, i = 1;
    char *str1, *str2;
    int result = 0, found = 0;
    struct node *head, *tail, *temp;
    int max = atoi(argv[1]);
    
    if(argc != 3)
    {
        printf("usage:    executableName  maxDistanceInteger  fileNameExtension\nexample:  ./aguilar-hw09  5  mp3\n");
        exit(1);
    }
    
    sprintf(pathname, "*.%s", argv[2]);
    csource = glob(pathname, 0, NULL, &paths);
    
    if (csource == 0)
    {
        for (p=paths.gl_pathv; p[i] != NULL; i++)
        {
            str1 = p[i-1];
            j = i;
            head = NULL;
            found = 0;
            for(p=paths.gl_pathv; p[j] != NULL; j++)
            {
                str2 = p[j];
                
                editDistance(str1, str2, &result);
        
                
                if(result <= max)
                {
                    temp = addNode(str2, result);

                    if(head == NULL)
                    {
                        head = temp;
                    }
                    else
                    {
                        tail->next = temp;
                    }
                    tail = temp;
                    /*printf("   %d, %s\n", result, str2);*/
                    found = 1;
                }
            }
            if(found == 1)
            {
                printf("%s\n", str1);
            }
            printList(head);
            freeList(head);
        }
        globfree(&paths); 
    }
}

void editDistance( char *str1, char *str2, int *result)
{
    int len1 = 0, len2 = 0;
    int **matrix;
    int i = 0, j = 0;
    int del = 0;
    int insert = 0;
    int substitute = 0;
    int min = 0;
    char c1, c2;
    
    len1 = strlen (str1);
    len2 = strlen (str2);
    
    matrix = malloc( (len1+1) * (sizeof(int*)) );
    
    for(i = 0; i < len1+1; i++)
    {
        matrix[i] = malloc( (len2+1) * (sizeof(int)) );
    }
    
    for (i = 0; i < len1+1; i++) {
        matrix[i][0] = i;
    }
    
    for (i = 0; i < len2+1; i++) {
        matrix[0][i] = i;
    }
    
    for (i = 1; i < len1+1; i++) {
   
        c1 = str1[i-1];
        for (j = 1; j < len2+1; j++) {
       

            c2 = str2[j-1];
            if (c1 == c2) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
        
                del = matrix[i-1][j] + 1;
                insert = matrix[i][j-1] + 1;
                substitute = matrix[i-1][j-1] + 1;
                min = del;
                if (insert < min) {
                    min = insert;
                }
                if (substitute < min) {
                    min = substitute;
                }
                matrix[i][j] = min;
            }
        }
    }
    *result =  matrix[len1][len2];
    
    for(i = 0; i < len1+1; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
struct node* addNode(char s[], int num)
{
    struct node* temp = malloc( sizeof(struct node) );
    temp->string2 = malloc(strlen(s)+1);
    strcpy(temp->string2, s);
    temp->x = num;
    temp->next = NULL;

    return temp;
}
void printList(struct node* head)
{
    while(head != NULL)
    {
        printf("   %2d, %s\n", head->x, head->string2);
        head = head->next;
    }
}
void freeList(struct node* head)
{
    struct node* temp;
    while(head != NULL)
    {
        
        temp = head->next;
        free(head->string2);
        free(head);
        head = temp;
    }
}
