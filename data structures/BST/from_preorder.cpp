#include<iostream>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

void Create(int pre[],int n){
    struct node *t,*p;
    stack<node *>stk;
    int i=0;
    root=new node;
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    while(i<n){
        if(pre[i]<p->data){
            t=new node;
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            stk.push(p);
            p=t;
        }
        else{
            if(pre[i]>p->data && pre[i]<(stk.empty()?357885:stk.top()->data)){
                t=new node;
                t->data=pre[i++];
                t->rchild=t->lchild=NULL;
                p->rchild=t;
                p=t;
            }
            else{
                p=stk.top();
                stk.pop();
            }
        }
    }
}

void Inorder(struct node *p){
  if(p){
      Inorder(p->lchild);
      cout<<p->data<<endl;
      Inorder(p->rchild);
  }
}

int main(){
    int pre[]={30, 20, 10, 15, 25, 40, 50, 45};
    Create(pre,8);
    Inorder(root);
    return 0;
}