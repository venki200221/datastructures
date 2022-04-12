#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
}*top=NULL;

void Push(int x){
    struct node *t=new node;
    if(!t){
        cout<<"stack overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void Display(struct node *p){
while(p){
    cout<<p->data<<endl;
    p=p->next;
}
}

int Pop(struct node *p){
    struct node *q=NULL;
    int x=-1;
    if(top==NULL){
        cout<<"stack underflow"<<endl;
    }
    else{
        q=p;
        p=p->next;
        x=q->data;
        delete q;
    }
    return x;
}
int Peek(struct node *p,int pos){
    int x=-1;
    struct node *q=p;
    for(int i=0;q!=NULL && i<pos-1;i++){
        q=q->next;
    }
    if(q){
        return q->data;
    }
    else{
        return x;
    }
}

int Stacktop(){
    if(top){
        return top->data;
    }else{
        return -1;
    }
}

bool isEmpty(){
    return top?0:1;
}
bool isFull(){
    struct node *t=new node;
    bool r=t?1:0;
    delete t;
    return r;
}




int main(){

Push(10);
Push(20);
Push(30);
Push(50);
Display(top);
cout<<Peek(top,3);
cout<<boolalpha<<isEmpty()<<endl;
}