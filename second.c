#include<stdio.h>
#include<stdlib.h>

struct node{
    char name[20];
    int id;
    int deposit;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(){
     struct node *t,*q;
    printf("Enter the number of nodes:\n");
    int n;
    scanf("%d",&n);
    printf("Enter the 1st element:");
    
    first=malloc(sizeof(struct node));
     scanf("%d ",&(first->id));
     scanf("%s",&(first->name));
     scanf("%d",&(first->deposit));
    first->next=NULL;
    q=first;
    for(int i=0;i<n-1;i++){
        printf("enter the %dth element:",i+2);
        
        t=malloc(sizeof(struct node));
        scanf("%d ",&t->id);
     scanf("%s",&t->name);
     scanf("%d",&t->deposit);
        t->next=NULL;
        q->next=t;
        q=t;        
    }
}

void Display(struct node *p){
while(p){
    printf("%d ",p->id);
    printf("%s ",p->name);
    printf("%d ",p->deposit);
    printf("\n");
    p=p->next;
}
}

void insert(struct node *p,int acc){
    struct node *t;
    
    while(p && p->id!=acc){
    p=p->next;
    }  
    t=p->next;
    struct node *newnode;
    newnode =malloc(sizeof(struct node));
    printf("Enter the new persons data:");
     scanf("%d ",&newnode->id);
     scanf("%s",&newnode->name);
     scanf("%d",&newnode->deposit);
     newnode->next=p->next;
     p=newnode;
}

void add_interest(struct node *p){
    while(p){
     if(p->deposit>50000){
        p->deposit+=((p->deposit*10)/100);
     }
     p=p->next;
    }

}




int main(){
    create1();
    Display(first);
    insert(first,3);
    add_interest(first);
    return 0;
}