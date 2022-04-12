#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    struct Queue **Q;
};

void Create(struct Queue *q,int size){
q->size=size;
q->front=q->rear=0;
q->Q=(struct Node **)malloc(q->size*sizeof(struct
Node *));
}

void enqueue(struct Queue *q,struct node *s){
    if((q->rear+1)%q->size==q->front){
        cout<<"The queue is full"<<endl;
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=s;
    }
}

struct node *Dequeue(struct Queue *q){
    struct node *s=NULL;
    if(q->rear==q->front){
        cout<<"The Queue is Empty"<<endl;
    }
    else{
        q->front=(q->front+1)%q->size;
        s=q->Q[q->front];
    }
    return s;
}

bool isempty(struct Queue q){
    return (q.rear==q.rear)?1:0;
}

struct node *root;

void CreateTree()
{
    struct node *p,*t;
    struct Queue q;
    Create(&q,100);
    int x;
    cout<<"Enter the value of root node"<<endl;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isempty(q)){
        p=Dequeue(&q);
        cout<<"Enter the value of left child of"<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
    
    cout<<"Enter the value of right child of:"<<p->data<<endl;
    cin>>x;
    if(x!=-1){
        t=new node;
        t->data=x;
        t->rchild=t->lchild=NULL;
        t->rchild=t;
        enqueue(&q,t);
    }
    }
}

void Preorder(struct node *p){

if(p){
    cout<<p->data<<endl;
    Preorder(p->lchild);
    Preorder(p->rchild);
}
}

void Inorder(struct node *p){
    if(p){
        postorder(p->lchild);
        cout<<p->data<<endl;
        postorder(p->rchild);
    }
}

void postorder(struct node *p){
if(p){
    postorder(p->lchild);
    postorder(p->rchild);
    cout<<p->data<<endl;
}
}



int main(){

CreateTree();
Preorder(root);


}