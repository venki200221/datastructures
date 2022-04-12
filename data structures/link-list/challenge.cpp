#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
}*first=NULL;

void Create(int arr[],int len){
    struct node *t,*last;
    first=new node;
    last=first;
    first->data=arr[0];
    first->next=NULL;
    for(int i=0;i<len;i++){
        t=new node;
        t->data=arr[i];
        t->next=NULL;
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

int Length(struct node *p){
    int count{};
    while(p->next){
        count++;
        p=p->next;
    }
    return count;
}

int Middle(struct node *p){
    struct node *q;
    q=p;
    while(p){
        p=p->next;
        if(p){
         p=p->next;
         q=q->next;
        }
    }
 return q->data;
}



int main()
{
int arr[]={1,2,3,4,5,6};
Create(arr,6);
cout<<"The length of linked list:"<<Length(first)<<endl;
Display(first);
cout<<"The Middle element is:"<<Middle(first)<<endl;


}