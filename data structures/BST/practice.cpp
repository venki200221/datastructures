#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

void insert(struct node *t,int key){
    struct node *r,*p=NULL;
    if(root==NULL){
        p=new node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(t->data==key){
            return;
        }
        else if(t->data<key){
            t=t->rchild;
        }
        else{
            t=t->lchild;
        }
    }
     p=new node;
        p->data=key;
        p->lchild=p->rchild=NULL;
    if(r->data<key){
        r->rchild=p;
    }
    else{
        r->lchild=p;
    }
}

void Inorder(struct node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<endl;
        Inorder(p->rchild);
    }
}

struct node *Search(struct node *t,int key){

while(t){
    if(t->data==key){
        return t;
    }
    else if(t->data<key){
        t=t->rchild;
    }
    else{
        t=t->lchild;
    }
}

return NULL;
}

struct node *rinsert(struct node *p,int key){
    struct node *t=NULL;
    if(p==NULL){
      t=new node ;
      t->data=key;
      t->lchild=t->rchild=NULL;
      return t;
    }
     if(p->data < key){
        p->rchild=rinsert(p->rchild,key);
    }
    else if(p->data>key){
        p->lchild=rinsert(p->lchild,key);
    }
    return p;
}

struct node *rsearch(struct node *t,int key){
    if(t==NULL){
        return NULL;
    }
    if(t->data==key){
        return t;
    }
    else if(t->data<key){
        return rsearch(t->rchild,key);
    }
    else{
        return rsearch(t->lchild,key);
    }
}

int Height(struct node *p){
    int x,y;
    if(!p){
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y ?x+1:y+1;
}
struct node *Inpre(struct node *p){
   while(p && p->rchild){
       p=p->rchild;
   }
   return p;
}

struct node *Insuc(struct node *p){
  while(p && p->lchild){
      p=p->lchild;
  }
  return p;
}



struct node *Delete(struct node *p,int key){
   struct node *q;
   
if(p==NULL){
    return NULL;
}
if(p->lchild==NULL && p->rchild==NULL){
    
    if(p==root)
    root=NULL;
    free (p);
    return NULL;
}


 if(key <p->data){
        p->lchild=Delete(p->lchild,key);
}
else if(key>p->data){
    p->rchild=Delete(p->rchild,key);
}
else{
    if(Height(p->lchild)>Height(p->rchild)){
      q=Inpre(p->lchild);
      p->data=q->data;
      p->lchild=Delete(p->lchild,q->data); 
    }
    else{
        q=Insuc(p->rchild);
        p->data=q->data;
        p->rchild=Delete(p->rchild,q->data);
    }

}
return p;
}







int main()
{
struct node *temp=NULL;
// insert(root,10);
// insert(root,1);
// insert(root,1);
// insert(root,20);
// insert(root,50);
// insert(root,7);
// insert(root,6);

root=rinsert(root,100);
rinsert(root,1000);
rinsert(root,10000);
rinsert(root,10);

Delete(root,100);
Inorder(root);

temp=Search(root,40);

if(temp){
    cout<<temp->data<<" Is found!"<<endl;
}
else{
    cout<<"Element not found"<<endl;
}

temp=rsearch(root,100);
if(temp){
    cout<<temp->data<<" Is found!"<<endl;
}
else{
    cout<<"Element not found"<<endl;
}


}