#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void Enqueue(struct Queue *q,int x){
if(q->rear==q->size-1){
    printf("queue overflow");
}
else{
    q->rear++;
    q->Q[q->rear]=x;
}
}

int Dequeue(struct Queue *q){
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

int main(){
    struct Queue q;
    q.front=-1;
    q.rear=-1;
    printf("Enter the size of Queue:\n");
    scanf("%d",&q.size);
    q.Q=malloc(sizeof(struct Queue));
    Enqueue(&q,5);
    Enqueue(&q,10);
    printf("%d",Dequeue(&q));
}