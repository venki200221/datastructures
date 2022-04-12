#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct Queue{
    int front=0;
    int rear=0;
    int size;
    int *Q;
};

void Enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size==q->front){
        cout<<"Queue overflow"<<endl;
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int Dequeue(struct Queue *q){
    int x=-1;
    if(q->rear==q->front){
    return x;
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
        return x;
    }
}

int main()
{
struct Queue q;
cout<<"Enter the size of Queue:"<<endl;
cin>>q.size;
q.Q=new int [q.size];
Enqueue(&q,5);
Enqueue(&q,10);
cout<<Dequeue(&q)<<endl;
Enqueue(&q,15);
cout<<Dequeue(&q)<<endl;
cout<<Dequeue(&q)<<endl;

}