#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node *next;
};

class Stack{
    private:
    node *top;
    public:
    Stack(){top=NULL;}
    void Push(int x);
    int Pop();
    void Display();

};

void Stack::Push(int x){
    node *t=new node;
    if(t==NULL){
        cout<<"Stack overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::Pop(){
    int x=-1;
    if(top==NULL){
        cout<<"Stack underflow"<<endl;
    }
    else{
        x=top->data;
        node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    node *p=top;
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}

int main()
{
    Stack stk;
    stk.Push(10);
    stk.Push(20);
    stk.Push(30);
    stk.Display();

cout<<stk.Pop()<<endl;

}