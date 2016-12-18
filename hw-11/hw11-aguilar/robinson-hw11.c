#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Quentin Robinson hw 11*/
struct preq{
    char class[50];
    struct preq *right;
};

struct class{
    char class[50];
    char note[50];
    int count;
    struct class *down;
    struct preq  *right;
};

void freeC(struct class *head);

void freeP(struct preq *head);

void eligible(char completed[][50],int a, struct class *head);

struct class* newClass(char * token);

struct preq* newPreq(char * token);

void printC(struct class * head);

void printP(struct preq * preq);

int main(int argc, char *argv[]){

    FILE* plan;
    FILE* taken;
    char buff[151];
    char completed[100][50],cpy[100];
    char *token, *temp;
    struct preq  *Phead, *Ptail, *Ptemp;
    struct class *Chead, *Ctail, *Ctemp;
    int Ccnt=0,Pcnt=0,cnt=0,i;

    plan=fopen(argv[1],"r");
    taken=fopen(argv[2],"r");

    while(fgets(buff,sizeof(buff),taken)!=NULL){
	temp=strtok(buff,"\n");
	strcpy(completed[cnt],temp);
/*	printf("%s\n",completed[cnt]);*/
	cnt++;
    }

    while(fgets(buff,sizeof(buff),plan)!=NULL){
	if(buff[0]!='#'){
	    strcpy(cpy,buff);
            token=strtok(buff,",");
	    Ctemp=newClass(token);
	    if(Ccnt==0){
		Chead=Ctemp;
		Ctail=Chead;
	    }
	    Ctail->down=Ctemp;
	    Ctail=Ctemp;
	    Ccnt++;

	    strtok(NULL,",");
	    token=strtok(NULL,",");

	    if(strcmp(token,"none")!=0){
		token=strtok(token,"|");
		while(token!=NULL){
		    Ptemp=newPreq(token);
		    if(Pcnt==0){
		        Ctail->right=Ptemp;
		    }
		    else{
		    	Ptail->right=Ptemp;
		    }
		    Ptail=Ptemp;
		    Ctail->count++;
		    Pcnt++;
		    token=strtok(NULL,"|");
		}
	    }
	    token=strtok(cpy,",");
	    token=strtok(NULL,",");
	    token=strtok(NULL,",");
	    token=strtok(NULL,",");
	    token=strtok(token,"\n");
		
	    strcpy(Ctail->note,token);
	    printf("%s -- %s\n",Ctail->class,Ctail->note);
	    Pcnt=0;
	}
    }
   

/*    printf("print function;\n");
    printC(Chead);*/
    printf("COURSES ELIGIBLE TO TAKE\n------------------------\n");

    eligible(completed,cnt,Chead);

    freeC(Chead);
}


struct class* newClass(char *token){
    
    struct class* temp= malloc(sizeof(struct class));
    strcpy(temp->class,token);
    temp->down=NULL;
    temp->right=NULL;

    return temp;
}

struct preq* newPreq(char *token){

    struct preq* temp=malloc(sizeof(struct preq));
    strcpy(temp->class,token);
    temp->right=NULL;

    return temp;
}

void printC(struct class *head){

    struct preq *temp;

    if(head==NULL)
	return;

    printf("class %s -%d- ",head->class,head->count);
    
    if(head->right==NULL){
	printf("no preq");
    }

    else{
        printP(head->right);
    }
    printf("\n");	
    printC(head->down);
}

void printP(struct preq *preq){

    if(preq==NULL)
	return;

    printf("%s  ",preq->class);
    printP(preq->right);
}

void eligible(char completed[][50],int a, struct class *head){

    int b=0,i,c=0;
    char *temp;

    if(head==NULL)
	return;
    if(head->count==0){
        for(i=0;i<a;i++){
            if(strcmp(head->class,completed[i])==0){
	        b++;
	    }
	}
        if(b==0){
	    printf("  %s",head->class);
	    if(strcmp(head->note,"none")!=0)
		printf("(%s)\n",head->note);
	    else
		printf("\n");
	}	
    }
    if(head->count>0){
        for(i=0;i<a;i++){
            if(strcmp(completed[i],head->right->class)==0){
		b++;
	        if(head->right->right !=NULL){
		    if(strcmp(completed[i],head->right->right->class)==0)
		        b++;
	            if(head->right->right->right !=NULL){
			if(strcmp(completed[i],head->right->right->right->class)==0)
		            b++;
	                if(head->right->right->right->right != NULL){
			    if(strcmp(completed[i],head->right->right->right->right->class)==0)
		                b++;
	    		}
	    	    }
		}
	    } 
	}   
	for(i=0;i<a;i++)
	    if(strcmp(head->class,completed[i])==0)
		c++;
	if(b==head->count && c==0){
	    printf("  %s ",head->class);
	    if(strcmp(head->note,"none")!=0)
	        printf("(%s)\n",head->note);
	    else
	        printf("\n");
	}
    }
    eligible(completed, a, head->down);
}

void freeP(struct preq *head){
    if(head==NULL || head->right==NULL)
	return;
    freeP(head->right);
    free(head->right);
}
void freeC(struct class *head){
    if(head==NULL || head->down==NULL)
	return;
    freeP(head->right);
    freeC(head->down);

}
