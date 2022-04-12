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
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

int Eval(char *postfix){
int i=0;
int x1,x2,r;
for(i=0;postfix[i]!='\0';i++){
    if(isOperand(postfix[i])){
        Push(postfix[i]-'0');
    }
    else{
        x2=Pop(top);
        x1=Pop(top);
        switch(postfix[i]){
            case '+':r=x1+x2;
             break;
             case '-':r=x1-x2;
             break;
             case '*':r=x1*x2;
             break;
             case '/':r=x1/x2;
             break;
        }
        Push(r);
    }
}
return Stacktop();
}



int main(){
char *postfix="234*+82/-";
cout<<"The result is:"<<Eval(postfix)<<endl;
}