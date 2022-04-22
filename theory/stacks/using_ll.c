#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *t=malloc(sizeof(struct node));
    if(!t){
        printf("Stack overflow");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
}
}

int pop(struct node *p){
    struct node *q=NULL;
    int x=-1;
    if(top==NULL){
        printf("struct overflow");
    }
    else{
        q=p;
        p=p->next;
        top=top->next;
        x=q->data;
        free(q);
    }
return x;
}

void display(struct node *p){
    while(p){
        printf("%d \n",p->data);
        p=p->next;
    }
}

int main(){
    push(100);
    push(200);
    push(300);
    pop(top);
    display(top);
}
