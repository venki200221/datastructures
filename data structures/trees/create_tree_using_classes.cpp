#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node{
public:
node *lchild;
int data;
node *rchild;
};

class Queue{
    private:
    int front;
    int rear;
    int size;
    node **Q;

public:
Queue(){front=rear=-1;size=10;Q=new node*[size];}
Queue(int size){front=rear=-1;Q=new node*[size];}
void Enqueue(node *x);
node* Dequeue();
bool Is_empty();
void Display();
};

class Tree{
public:
node *root;
Tree (){root=NULL;}
void CreateTree();
void Preorder(struct node*p);
void Postorder(struct node*p);
void Inorder(struct node*p);
void Levelorder(struct node*p);
int Height(struct node *root);
};

void Queue::Enqueue(node *x){
if(rear==size-1){
cout<<"The Queue is full"<<endl;
}
else{
    rear++;
    Q[rear]=x;
}
}

node *Queue::Dequeue(){
    node *x=NULL;
    if(front==rear){
        cout<<"The queue is empty"<<endl;
    }
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}

bool Queue::Is_empty(){
return (front==rear)?1:0;
}

void Tree::CreateTree(){
node *p,*t=NULL;
int x;
Queue q(100);

cout<<"Enter the value of root:"<<endl;
cin>>x;

root=new node;
root->data=x;
root->lchild=root->rchild=NULL;
q.Enqueue(root);

while(!q.Is_empty()){
    p=q.Dequeue();
    cout<<"Enter left child of "<<p->data<<endl;
    cin>>x;
    if(x!=-1){
        t=new node;
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->lchild=t;
        q.Enqueue(t);
    }
    cout<<"Enter the right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
        t=new node;
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        q.Enqueue(t);
}
}
}

void Tree::Preorder(struct node *p){
if(p){
    cout<<p->data<<endl;
    Preorder(p->lchild);
    Preorder(p->rchild);
}
}

void Tree::Postorder(struct node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<endl;
    }
}

void Tree::Inorder(struct node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<endl;
        Inorder(p->rchild);
    }
}

void Tree::Levelorder(struct node *root){
Queue q(100);

cout<<root->data<<endl;
q.Enqueue(root);

while(!q.Is_empty()){
root=q.Dequeue();
if(root->lchild){
cout<<root->lchild->data<<endl;
q.Enqueue(root->lchild);
}
if(root->rchild){
    cout<<root->rchild->data<<endl;
    q.Enqueue(root->rchild);
}
}
}

int Tree::Height(struct node *root){
int x=0,y=0;
if(root==0){
    return 0;
}
x=Height(root->lchild);
y=Height(root->rchild);
if(x>y){
    return x+1;
}
else{
    return y+1;
}
}

int main ()
{
Tree t;
 t.CreateTree();
 cout<<"Preorder ";
 t.Preorder(t.root);
 cout<<endl;
 cout<<"Inorder ";
 t.Inorder(t.root);
 cout<<endl<<endl; 
 return 0;
}


