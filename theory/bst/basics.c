#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

void insert(int key){
    struct node *t=root;
    struct node *p,*r;
    if(root==NULL)
    {
        p=malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t){
        r=t;
        if(key<t->data){
            t=t->lchild;
        }
        else if(key>t->data){
            t=t->rchild;
        }
        else{
            return;
        }
    }
    p=malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data){
        r->lchild=p;
    }
    else{
        r->rchild=p;
    }
}

struct node *rinsert(struct node *p,int key){
    struct node *t=NULL;
    if(!p){
        t=malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data){
        p->lchild=rinsert(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=rinsert(p->rchild,key);
    }
    return p;
}

struct node *search(int key){
    struct node *t=root;
    while(t){
        if(key<t->data){
        t= t->lchild;
    }
    else if(key>t->data){
        t= t->rchild;
    }
    else if(key == t->data){
        t= t;
    }
    }
    return NULL;
}

struct node *rsearch(struct node *p,int key){
    if(key==p->data){
        return p;
    }
    else if(key<p->data){
        p->lchild=rsearch(p->lchild,key);
    }
    else{
        p->rchild=rsearch(p->rchild,key);
    }
}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        printf("%d \n",p->data);
        inorder(p->rchild);
    }
}

struct node *Insuc(struct node *p){
    while(p && p->lchild){
        p=p->lchild;
    }
    return p;
}

struct node *Inpre(struct node *p){
    while(p && p->rchild){
        p=p->rchild;
    }
    return p;
}

int height(struct node *p){
    int x,y;
    if(!p){
      return NULL;
    }
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y?x+1:y+1;
}

struct node *delete(struct node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root){
            root =NULL;
        }
        free(p);
        return NULL;
    }
    struct node *q=NULL;
    if(key<p->data){
        p->lchild=delete(p->lchild,p->data);
    }
    else if(key>p->data){
        p->rchild=delete(p->rchild,p->data);
    }
    else{
        if(height(p->lchild)>height(p->rchild)){
            q=Inpre(p->lchild);
            p->data=q->data;
            free(q);
        }
        else{
            q=Insuc(p->rchild);
            p->data=q->data;
            free(q);
        }
    }
    return p;
}

int count(struct node *p){
    int x,y;
    if(p){
        x=count(p->lchild);
        y=count(p->rchild);
        if(!p->lchild && !p->rchild){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
}


int main(){
    // insert(10);
    // insert(20);
    // insert(15);
    root=rinsert(root,25);
    rinsert(root,14);
    rinsert(root,40);
    delete(root,14);
    inorder(root);
}
