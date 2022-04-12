#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
 class node{
     public:
     int data;
     node *next;
 };

 class linkedList{
     private:
     node *first;
     public:
     linkedList(){first=NULL;}
     linkedList(int arr[],int n);
     ~linkedList();
     void Display();
     void Insert(int index,int x);
     int Delete(int index);
     int Length();
 };
linkedList::linkedList(int arr[],int n){
    struct node *last,*t;
    int i=0;
    first=new node;
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new node;
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
linkedList::~linkedList(){
    node *p=first;
    while(p){
        first=first->next;
        delete p;
        p=first;
    }
}
void linkedList::Display(){
node *p=first;
while(p){
    cout<<p->data<<endl;
    p=p->next;
}
}
int linkedList::Length(){
    node *p=first;
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
void linkedList::Insert(int index,int x){
    node *t=new node;
    t->data=x;
    node *p=first;
    for(int i=0;i<index-1;i++){
      p=p->next;
    }
    t->next=p->next;
    p->next=t;
}
int linkedList::Delete(int index){
    node *p=first;
    node *q=NULL;
    for(int i=0;i<index-1;i++){
       q=p;
       p=p->next;
    }
    q->next=p->next;
    int x=p->data;
    delete p;
    return x;

}

int main()
{
    int arr[]={1,2,3,4,5};
    linkedList l(arr,5);
    
    l.Display();
   
 

}