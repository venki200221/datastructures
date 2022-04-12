#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
}*front,*rear;

void Enqueue(struct node *p,int x){
 struct node *t=new node;
 if(t==NULL){
     cout<<"The Queue is full"<<endl;
 }
 else{
     t->data=x;
     t->next=NULL;
 }
 if(front==NULL){
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
   delete p;
    }
    return x;
}
void Display(struct node *p){
    struct node *q;
    q=front;
    while(q){
        cout<<q->data<<endl;
        q=q->next;
    }
}


int main(){
    struct node *Queue;
    Enqueue(Queue,5);
    Enqueue(Queue,10);
    Display(Queue);
   cout<< Dequeue(Queue)<<endl;

}