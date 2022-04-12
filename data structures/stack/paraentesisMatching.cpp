#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
    char data;
    struct node *next;
}*top=NULL;

void Push(char x){
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

int Pop(){
    struct node *q=NULL;
    char x=-1;
    if(top==NULL){
        cout<<"stack underflow"<<endl;
    }
    else{
        q=top;
        top=top->next;
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
bool isBalanced(char *exp){

for(int i=0;exp[i]!='\0';i++){
    if(exp[i]=='('){
        Push(exp[i]);
    }
    else if(exp[i]==')'){
        if(top==NULL)
            return 0;
        Pop();
    }
}
if(top==NULL){
return 1;
}
else{
return 0;
}


}



int main(){

char *exp="((a+b)*(c+d))";

cout<<boolalpha<<isBalanced<<endl;

}