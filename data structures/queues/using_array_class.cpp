#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class Queue{
private:
int front;
int rear;
int size;
int *Q;

public:
Queue();
Queue(int size);
void Enqueue(int x);
int Dequeue();
void Display();
};

Queue::Queue(){
    front =-1;rear=-1;size=10;Q=new int [size];
}
Queue::Queue(int size){
    front=rear=-1;
    this->size=size;
    Q=new int [this->size];
}

void Queue::Enqueue(int x){
    if(rear==size-1){
        cout<<"Queue overflow"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}
int Queue::Dequeue(){
    int x=-1;
    if(front==rear){
        return x;
    }
    else{
        front++;
        x=Q[front];
        return x;
    }
}
void Queue::Display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<endl;
    }
}


int main()
{
class Queue q(5);
q.Enqueue(5);
q.Enqueue(10);
cout<<q.Dequeue()<<endl;
q.Display();


}