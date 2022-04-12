#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int x){
    struct node *t=malloc(sizeof(struct node));
    if(!t){
        printf("stack overflow");
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
        printf("stack olverflow");
    }
    else{
        q=p;
        p=p->next;
        x=q->data;
        free(q);
    }
    return x;
}

int peek(struct node *p,int pos){
    int x=-1;
    struct node *q=p;
    for(int i=0;i<q!=NULL && i<pos-1;i++){
        q=q->next;
    }
    if(q){
        return q->data;
    }
    else{
        return x;
    }
}
void Display(struct node *p){
    while(p){
        printf("%d \n",p->data);
        p=p->next;
    }
}

int stackTop(){
    if(top){
        return top->data;
    }
    else{
        return -1;
    }
}

int main(){
    push(100);
    push(200);
    push(300);
    Display(top);
}


