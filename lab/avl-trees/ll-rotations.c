#include<stdio.h>
#include<stdlib.h>


struct node{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
}*root=NULL;

int node_height(struct node *p){
    int hl,hr;
    hl= p && p->lchild?p->lchild->height:0;
    hr= p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}

int bf(struct node *p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}

struct node *llrotation(struct node *p){
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=node_height(p);
    pl->height=node_height(pl);

    if(root==p){
        root=pl;
    }
    return pl;
}

struct node *lrrotation(struct node *p){
    struct node *pl,*plr;
    pl=p->lchild;
    plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=node_height(pl);
    p->height=node_height(p);
    plr->height=node_height(plr);

    if(p==root){
        root=plr;
    }

    return plr;

}

struct node *rrrotation(struct node *p){
    struct node *pr,*prl;
    pr=p->rchild;
    prl=pr->lchild;

    pr->lchild=p;
    p->rchild=prl;
    p->height=node_height(p);
    pr->height=node_height(pr);

    if(p==root){
        root=pr;
    }
    return pr;

}

struct node *rlrotation(struct node *p){
    struct node *pr=p->rchild;
    struct node *prl=pr->lchild;

    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;

    prl->lchild=p;
    prl->rchild=pr;

    p->height=node_height(p);
    pr->height=node_height(pr);
    prl->height=node_height(prl);

    if(p==root){
        root=prl;
    }
    return prl;
}


struct node *rinsert(struct node *p,int key){
    struct node *t=NULL;
    if(p==NULL){
        t=malloc(sizeof(struct node));
        t->lchild=t->rchild=NULL;
        t->height=1;
        t->data=key;
        return t;
    }
    if(key<p->data){
        p->lchild=rinsert(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=rinsert(p->rchild,key);
    }
    p->height=node_height(p);

    if(bf(p)==2 && bf(p->lchild)==1){
        return llrotation(p);
    }
    else if(bf(p)==2 && bf(p->lchild)==-1){
        return lrrotation(p);
    }
    else if(bf(p)==-2 && bf(p->rchild)==-1){
        return rrrotation(p);
    }
    else if(bf(p)==-2 && bf(p->rchild)==1){
         return rlrotation(p);
    }
    return p;
}

void inorder(struct node *p){
    if(p){
        inorder(p->lchild);
        printf("%d",p->data);
        inorder(p->rchild);
    }

}



int main(){
root=rinsert(root,10);
rinsert(root,30);
rinsert(root,20);
printf("%d\n",root->data);
inorder(root);
}