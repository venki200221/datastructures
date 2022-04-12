#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

void Create(int a[],int n);
void Display(struct node *h);
void rdisplay(struct node *h);
void Insert(struct node *p,int index,int x);


using namespace std;

struct node{
    int data;
    struct node *next;
}*Head;

void Create(int a[],int n){
    int i;
    struct node *t,*last;
    Head=new node;
    Head->data=a[0];
    Head->next=Head;
    last=Head;
    for(int i=1;i<n;i++){
       t=new node;
       t->data=a[i];
       t->next=last->next;
       last->next=t;
       last=t;
    }
}
void Display(struct node *h){
    do{
        cout<<h->data<<endl;
        h=h->next;
    }while(h!=Head);
}

void rdisplay(struct node *h){
    static int flag=0;
    if(h!=Head || h==0){
     flag=1;
     cout<<h->data<<endl;
     rdisplay(h->next);
    }
    flag=0;
}
void Insert(struct node *p,int index,int x){
    struct node *t;
    if(index==0){
        t=new node;
        t->data=x;
    if(Head==NULL){
        Head=t;
        Head->next=Head;
    }
    else{
    while(p->next!=NULL){
     p=p->next;
    }
    p->next=t;
    t->next=Head;
    Head=t;
    } 
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t=new node;
        t->data=x;
        t->next=t;
    }
}
int Delete(struct node *p,int index){
struct node *q;
int i,m;

if(index==1){
    while(p->next != Head){p=p->next;}
    m=Head->data;
    if(Head==p){
        delete Head;
        Head=NULL;
    }
    else{
        p->next=Head->next;
          delete Head;
          Head=p->next;
    }
}
else{
    for(i=0;i<index-2;i++){
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    m=q->data;
    delete Head;
}
return m;
}
int main()
{
    int A[]={1,2,3,4,5,6};
    Create(A,6);
    Delete(Head,2);
    Insert(Head,2,10);
    Display(Head);
    // rdisplay(Head);
}