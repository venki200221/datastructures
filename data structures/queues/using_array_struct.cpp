#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

struct Queue{
    int size;
    int front=-1;
    int rear=-1;
    int *Q;
};
void Enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1){
        cout<<"queue overflow"<<endl;
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



int main()
{
struct Queue q;
cout<<"Enter the size of Queue"<<endl;
cin>>q.size;
q.Q=new int[q.size];
Enqueue(&q,5);
Enqueue(&q,10);
cout<<Dequeue(&q)<<endl;


}