
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front;
    int rear;
    int size;
    int *Q;
};

void Enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int Dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        return x;
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
        return x;
    }
}

int main(){
    struct Queue q;
    q.front=0;
    q.rear=0;
    printf("Enter the size of queue:\n");
    scanf("%d",&q.size);
    q.Q=calloc(q.size,sizeof(int));
    Enqueue(&q,10);
    Enqueue(&q,20);
    printf("%d",Dequeue(&q));
}