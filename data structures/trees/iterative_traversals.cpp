#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node *lchild;
    Node *rchild;
};

class Tree{

private:
Node *root;

public:
Tree();
~Tree();
void CreateTree();
void Preorder(Node *p);
void Preorder(){Preorder(root);}
void Inorder(Node *p);
void Inorder(){Inorder(root);}
void Postorder(Node *p);
void Postorder(){Postorder(root);}
void iterativepreorder(Node *p);
void iterativeinorder(Node *p);
void iterativepostorder(Node *p);
};

Tree::Tree(){
    root=NULL;
}
Tree::~Tree()
{}

void Tree::CreateTree(){
Node*p;
Node*t;
int x;
queue<Node*>q;


root=new Node;
cout<<"Enter the data of the root:"<<endl;
cin>>x;
root->data=x;
root->lchild=root->rchild=NULL;
q.emplace(root);

while(!q.empty()){
p=q.front();
q.pop();

cout<<"Enter the data of "<<p->data<<":"<<endl;
cin>>x;

if(x!=-1){
    t=new Node;
    t->data=x;
    t->lchild=t->rchild=NULL;
    p->lchild=t;
    q.emplace(t);
}

cout<<"Enter the data of"<<p->data<<endl;
cin>>x;
if(x!=-1){
t=new Node;
t->data=x;
t->rchild=t->lchild=NULL;
p->rchild=t;
q.emplace(t);
}
}
}

void Tree::Preorder(Node *p){
    if(p){
        cout<<p->data<<endl;
        Preorder(p->lchild);
        Preorder(p->rchild);

    }
}
void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<endl;
        Inorder(p->rchild);
    }
}
void Tree::Preorder(Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<endl;
    }
}

void Tree::iterativepreorder(Node *p){
stack<Node *> stk;
while(p!=NULL ||!stk.empty()){
if(p!=NULL){
    cout<<p->data<<endl;
    stk.emplace(p);
    p=p->lchild;
}
else{
    p=stk.top();
    stk.pop();
    p=p->rchild;
}
}
}

void Tree::iterativeinorder(Node *p){
stack <Node *> stk;
while(p!=NULL || !stk.empty()){
if(p!=NULL){
    stk.emplace(p);
    p=p->lchild;
}
else{
    p=stk.top();
    stk.pop();
    cout<<p->data<<endl;
    p=p->rchild;
}
}
}

void Tree::iterativepostorder(Node *p){
stack<Node *>stk;
long int temp;
while(p!=NULL || !stk.empty()){
    if(p!=NULL){
        stk.emplace((long int)p);
        p=p->lchild;
    }
    else{
     temp=(long int)stk.top();
     stk.pop();
     if(temp>0){
       stk.emplace(-temp);
       p=((Node*)temp)->rchild;
     }
     else{
         cout<<((Node*)(-1*temp))->data<<endl;
         p=NULL;
     }
    }
}
}

int main()
{
Tree bt;

bt.CreateTree();
cout<<endl;

cout<<"The preorder traversal:"<<endl;
bt.Preorder();
cout<<"-------------------------"<<endl;
cout<<"The iterative preorder traversal:"<<endl;
// bt.iterativepreorder();
cout<<"-------------------------"<<endl;
cout<<"The inorder traversal:"<<endl;
bt.Inorder();
cout<<"-------------------------"<<endl;
cout<<"The iterative inorder traversal:"<<endl;
// bt.iterativeinorder();
cout<<"-------------------------"<<endl;
cout<<"The postorder traversal:"<<endl;
bt.Postorder();
cout<<"-------------------------"<<endl;
cout<<"The iterative postoder:"<<endl;
// bt.iterativepostorder();


return 0;
}