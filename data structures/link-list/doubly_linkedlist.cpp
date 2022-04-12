#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
struct node *prev;
int data;
struct node *next;
}*first=NULL;

void Create(int arr[],int n){
    struct node *t,*last;
first=new node;
first->data=arr[0];
first->prev=first->next=NULL;
last=first;
for(int i=0;i<n;i++){
    t=new node;
    t->data=arr[i];
    t->next=last->next;
    t->prev=last;
    last->next=t;
    last=t;
}
}

void Display(struct node *p){
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}

int length(struct node *p){
    int count{};
    while(p->next!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

void Insert(struct node *p,int pos,int x){
struct node *t;
struct node *q=NULL;
if(pos==0){
    t=new node;
    t->data=x;
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
}
else{
    
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    t=new node;
    t->data=x;
    t->prev=p;
    t->next=p->next;
    if(p->next)
    {p->next->prev=t;}
    p->next=t;
}
}

int Delete(struct node *p,int pos){
    struct node *q;
    q=p;
    int x;
    if(pos==1){
    p=p->next;
    x=q->data;
    delete q;
    }
    else{
        for(int i=0;i<pos-1;i++){
            q=q->next;
        }
        q->prev->next=q->next;
        if(q->next){
            q->next->prev=q->prev;
        }
        x=q->data;
        delete q;
    }
    return x;
}

void Reverse(struct node *p){
    struct node *temp;
    while(p){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }

    }
}

int main(){

int arr[]={10,20,30,40,50};
Create(arr,5);
// cout<<"The number of elements of linked-list are:"<<length(first)<<endl;
// Insert(first,0,60);
// cout<<"The deleted element is->"<<Delete(first,1)<<endl;
Reverse(first);
Display(first);


}