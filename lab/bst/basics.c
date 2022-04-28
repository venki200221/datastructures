#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root=NULL;

void insert(int key){
    struct node *t=root;
    struct node *p,*r;
    if(root==NULL){
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
        t->rchild=t->lchild=NULL;
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
        if(key==t->data){
            return t;
        }
        else if(key<t->data){
        t= t->lchild;        
        }
        else{
        t=t->rchild;
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

int Height(struct node *p){
    int x,y;
    if(!p){
        return 0;
    }
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}

struct node *Delete(struct node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root){
            root=NULL;
        }
        free(p);
        return NULL;
    }
    struct node *q=NULL;
    if(key<p->data){
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild)>Height(p->rchild)){
           q=Inpre(p->lchild);
           p->data=q->data;
        //    free(q);
        p->lchild=Delete(p->lchild,q->data);
        }
        else{
            q=Insuc(p->rchild);
            p->data=q->data;
            // free(q);
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}

int count(struct node *p){
    int x,y;
    if(p){
        x=count(p->lchild);
        y=count(p->rchild);
        if(!p->lchild   && !p->rchild){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
}


void Inorder(struct node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d\n",p->data);
        Inorder(p->rchild);
    }
}

void Preorder(struct node *p){
    if(p){
        printf("%d\n",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Postorder(struct node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d\n",p->data);
    }
}

int main(){
    // insert(10);
    // insert(20);
    // insert(70);
    // insert(50);
    root=rinsert(root,5);
    rinsert(root,25);
    rinsert(root,15);
    rinsert(root,35);
    printf("%d\n",count(root));
    Delete(root,25);
    // printf("%s",search(15));
    Inorder(root);
    // Preorder(root);
    // Postorder(root);

}

