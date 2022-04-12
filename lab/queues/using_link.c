#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*front,*rear;

void Enqueue(struct node *p,int x){
    struct node *t=malloc(sizeof(struct node));
    if(!t){
        printf("Queue overflow");
    }
    else{
        t->data=x;
        t->next=NULL;
    }
    if(rear==NULL){
        front=rear=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}

int Dequeue(struct node *q){
    int x=-1;
    if(front==NULL){
        return x;
    }
    else{
        struct node *p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}
void Display(struct node *p){
    struct node *q;
    q=front;
    while(q){
        printf("%d\n",q->data);
        q=q->next;
    }
}

int main(){
    struct node *Queue;
    Enqueue(Queue,5);
    Enqueue(Queue,20);
    Display(Queue);
    printf("%d",Dequeue(Queue));
}