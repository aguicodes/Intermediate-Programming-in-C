/* Graciela Aguilar
   March 30, 2016
   HW08 - link lists
*/   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw08-header.h" 

struct node * enqueue(char name[], char course[], int numList);
struct node * dequeue(struct node *head, int numList);
void freeLists(struct node* head, int numList);

struct node {
   char name[15];
   char course[15];
   struct node *next;
};

int main(int argc, char* argv[])
{
   int i = 0;
   char *value = "go";
   int key;
   struct node *headOne = NULL, *tailOne, *temp;
   struct node *headTwo = NULL, *tailTwo;
   struct node *headThree = NULL, *tailThree;
   char *tok1, *tok2, *tok3, *tok4, *del = ",\n";

   if(argc != 2)
   {
      printf("  usage:  program_name positive_integer\n");
      printf("example:  ./example-hw08  123\n");
      exit(1);
   }
    
   key = atoi(argv[1]);
   initialize(key);

   while(strcmp(value, "stop") != 0)
   {
      value = getString();
      tok1 = strtok(value, del);
      if(strcmp(tok1, "enqueue") == 0)
      {
         tok2 = strtok(NULL, del);
         tok3 = strtok(NULL, del);
         tok4 = strtok(NULL, del);

         if((atoi(tok2)) == 1)
         {
            temp = enqueue(tok4, tok3, 1);

            if(headOne == NULL)
            {
               headOne = temp;
            }
            else
            {
               tailOne->next = temp;
            }
            tailOne = temp;
         }
         else if ((atoi(tok2)) == 2)
         {
            temp = enqueue(tok4, tok3, 2);

            if(headTwo == NULL)
            {
               headTwo = temp;
            }
            else
            {
               tailTwo->next = temp;
            }
             
            tailTwo = temp;
         }
         else if ((atoi(tok2)) == 3)
         {
            temp = enqueue(tok4, tok3, 3);

            if(headThree == NULL)
            {
               headThree = temp;
            }
            else
            {
               tailThree->next = temp;
            }
              
            tailThree = temp;
         }
      }
      else if(strcmp(tok1, "dequeue") == 0)
      {
         tok2 = strtok(NULL, del);
         if((atoi(tok2)) == 1)
         {
            headOne = dequeue(headOne,1);
         }
         else if((atoi(tok2)) == 2)
         {
            headTwo = dequeue(headTwo,2);
         }
         else if((atoi(tok2)) == 3)
         {
            headThree = dequeue(headThree,3);
         }
      }
   }
   printf("stop received; processing remaining students\n");
   freeLists(headOne, 1);
   freeLists(headTwo, 2);
   freeLists(headThree, 3);
}

struct node * enqueue(char name[], char course[], int numList)
{
   
   struct node* temp = malloc( sizeof(struct node) );
    strcpy(temp->name, name);
    strcpy(temp->course, course);
    printf("%s enters line %d to register for %s\n", temp->name, numList, temp->course);
    
    temp->next = NULL;

    return temp;
}

struct node * dequeue(struct node *head, int numList)
{
   struct node* temp;
   
   if (head == NULL)
   {
      printf("line %d is currently empty\n", numList);
      return head;
   }
   printf("%s leaves line %d\n", head->name, numList);
   temp = head->next;
   free(head);

   return temp;
}
void freeLists(struct node* head, int numList)
{
   struct node* temp;
   while(head != NULL)
   {
      printf("%s leaves line %d\n", head->name, numList);
      temp = head->next;
      free(head);
      head = temp;
   }
}
