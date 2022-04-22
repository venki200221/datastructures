#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1){
        printf("Queue overflow");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        return x;
    }
    else{
        q->front++;
        x=q->Q[q->front];
        return x;
    }
}

void display(struct Queue *q){
    for(int i=q->front+1;i<=q->rear;i++){
        printf("%d \n",q->Q[i]);
    }
}

int main(){
    struct Queue q;
    q.front=-1;
    q.rear=-1;
    printf("Enter the size of the Queue:");
    scanf("%d",&q.size);
    q.Q=calloc(q.size,sizeof(int));
    enqueue(&q,5);
    enqueue(&q,10);
    enqueue(&q,15);
    printf("%d\n",dequeue(&q));
    display(&q);
    enqueue(&q,15);
        display(&q);


    return 0;
}