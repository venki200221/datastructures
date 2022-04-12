#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root;

void Createtree(){
    struct Node*p,*t;
    int x;
    queue<Node*> q;
    
    cout<<"Enter the value of root node:"<<endl;
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.push(root);
    while(!q.empty()){
     p=q.front();
     q.pop();
     cout<<"Enter the left child of "<<p->data<<endl;
     cin>>x;
     if(x!=-1){
         t=new Node;
         t->data=x;
         t->lchild=t->rchild=NULL;
         p->lchild=t;
         q.push(t);
     }
     cout<<"Enter the right child of "<<p->data<<endl;
     cin>>x;
     if(x!=-1){
         t=new Node;
         t->data=x;
         t->lchild=t->rchild=NULL;
         p->rchild=t;
         q.push(t);
     }
    }
}

void level_order(struct Node *p){

queue<Node*>k;
cout<<p->data<<endl;
k.push(p);

while(!k.empty()){

p=k.front();
k.pop();

if(p->lchild){
    cout<<p->lchild->data<<endl;
    k.push(p->lchild);
}
if(p->rchild){
    cout<<p->rchild->data<<endl;
    k.push(p->rchild);
}
}
}

int main()
{

 Createtree();
 level_order(root);
 return 0;

}