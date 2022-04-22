#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*first=NULL;

void create(){
    struct node *t,*last;
    printf("Enter the number of nodes:");
    int n;
    int num;
    scanf("%d",&n);
    printf("Enter the data of 1st node:");
    scanf("%d",&num);
    first=malloc(sizeof(struct node));
    first->data=num;
    first->next=first->prev=NULL;
    last=first;
    for(int i=0;i<n-1;i++)
    {
        t=malloc(sizeof(struct node));
        printf("Enter the data of %d th node:",i+2);
        scanf("%d",&num);
        t->data=num;
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void display(struct node *p){
    while(p){
        printf("%d\n",p->data);
        p=p->next;
    }
}

int length(struct node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

void Insert(struct node *p,int pos,int x){
    struct node *t;
    struct node *q=NULL;
    if(pos==0){
        t=malloc(sizeof(struct node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t=malloc(sizeof(struct node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}

int delete(struct node *p,int pos){
    struct node *q;
    q=p;
    int x;
    if(pos==1){
        p=p->next;
        x=p->data;
        free(q);
    }
    else{
        for(int i=0;i<pos-1;i++){
            q=q->next;
        }
        q->prev->next=q->next;
        if(q->next){
            q->next->prev=q->prev;
        }
        x=q->data;
        free(q);
    }
    return x;
}

void rev(struct node *p){
    struct node *temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}



int main(){
create();
display(first);
printf("The number of nodes is:%d",length(first));
}