#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void create(int arr[],int n);
void create2(int arr[],int n);
void Display(struct node *p);
void rdisplay(struct node *p);
int count(struct node *p);
int rcount(struct node *p);
int add(struct node *p);
int radd(struct node *p);
int maxi(struct node *p);
int rmaxi(struct node *p);
void Insert(struct node *p,int index,int x);
void Sortedinsert(struct node *p,int x);
int Delete(struct node *p,int pos);
bool sorted(struct node *p);
void Remove_Duplicates(struct node *p);
void Reverse1(struct node *p);
void Reverse2(struct node *p);
void Reverse3(struct node *q,struct node *p);
void concatination(struct node *p,struct node *q);
void Merge(struct node *p,struct node *q);
bool is_loop(struct node *f);

struct node{
    int data{};
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int arr[],int n){
    int i{};
 struct node *t,*last;

first =new struct node;
first->data=arr[0];
first->next=NULL;
last=first;

for(i=1;i<n;i++){
    t=new struct node;
    t->data=arr[i];
    t->next=NULL;
    last->next=t;
    last=t;
}
}

void create2(int arr[],int n){
    int i{};
 struct node *t,*last;

second =new struct node;
second->data=arr[0];
second->next=NULL;
last=second;

for(i=1;i<n;i++){
    t=new struct node;
    t->data=arr[i];
    t->next=NULL;
    last->next=t;
    last=t;
}
}

void Display(struct node *p){
    cout<<"the elements of linked list(using loop) are:"<<endl;
    while(p!= NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}

void rdisplay(struct node *p){
    if(p!=NULL){
        cout<<p->data<<endl;
        rdisplay(p->next);
    }
}

int count(struct node *p){
    int x=0;
    while(p){
        x++;
        p=p->next;
    }
    return x;
}

int rcount(struct node *p){
    int x=0;
    if(p==0){
        return x;
    }
    else{
        x=rcount(p->next);
        return x+1;
    }
}

int add(struct node *p){
    int sum=0;
    while(p)                 //equivalent to p!=0
    {            
     sum+=p->data;
     p=p->next;
    }
    return sum;
}

int radd(struct node *p){
    if(!p){
        return 0;
    }
    else{
        return radd(p->next)+p->data;
    }
}

int maxi(struct node *p){
    int high=0;
    while(p){
    if((p->data)>high){
        high=p->data;
        p=p->next;
    } 
    }
    return high;
}

int rmaxi(struct node *p){
    int x=0;
    if(p==0){
        return 0;
    }
    else{
     x=maxi(p->next);
     return x>p->data?x:p->data;
    }
}

struct node *find(struct node *p,int key){
 struct node *q=NULL;
 while(p){
if(key==p->data){
    q->next=p->next;
    p->next=first;
    first=p;
    return p;
}
q=p;
p=p->next;
}
}

struct node *rfind(struct node *p,int key){
if(!p){
    return NULL;
}
else{
    if(key==p->data){
        return p;
    }
    else{
        rfind(p->next,key);
    }
}

}
void Insert(struct node *p,int index,int x){
struct node *t=new node;
 if(index<0 || index>count(p)){
     return;
 }
 else{
if(index==0){
t->data=x;
t->next=first->next;
first=t;
}
else{
    p=first;
    for(int i=0;i<index-1 && p;i++){
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
}
}
}

void Sortedinsert(struct node *p,int x){
struct node *t,*q=NULL;
t=new node;
t->data=x;
t->next=NULL;
if(first==NULL){
    first=t;
}
else{
    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==first){
        t->next=first;
        first=t;
    }
    else{
        t->next=q->next;
        q->next=t;
    }
}
}

int Delete(struct node *p,int pos){
    struct node *q;
    int x{};
    if(pos==1){
        x=first->data;
        p=first;
        first=first->next;
        delete p;
        return x;
    }
    else{
        q=NULL;
        for(int i=0;i<pos-1 && p;i++){
            q=p;
            p=p->next;
        }
        if(p){
        x=p->data;
        q->next=p->next;
        delete p;
        return x;
        }
    }
}

bool sorted(struct node *p){
    p=first;
    int x=-32768;
    while(p!=NULL){
     if(p->data<x){
         return 0;
     }
         x=p->data;
         p=p->next;
         
    }
    return 1;
}

void Remove_Duplicates(struct node *p){
p=first;
struct node *q=p->next;
while(q!=NULL){
if(p->data != q->data)
{
    p=q;
    q=q->next;
}
else{
    p->next=q->next;
    delete q;
    q=p->next;
}
}
}

// reversing a link list
// method 1-Using auxillary array
void Reverse1(struct node *p){
    int arr[count(first)];
    p=first;
    int i=0;
    while(p!=NULL){
        arr[i]=p->data;
        i++;
        p=p->next;
    }
    p=first;i--;
    while(p!=NULL){
        p->data=arr[i];
        p=p->next;
        i--;
    }
}

//method 2-using sliding pointers-most used
void Reverse2(struct node *p){
    p=first;
    struct node *q,*r=NULL;
    while(p!=NULL){
     r=q;
     q=p;
     p=p->next;
     q->next=r;
    }
    first=q;
}

// method 3-using recursion
void Reverse3(struct node *q,struct node *p){
    if(p!=NULL){
        Reverse3(p,p->next);
        p->next=q;

    }
    else{
        first=q;
    }
}

void concatination(struct node *p,struct node *q){
    struct node *r=first;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=second;
    second=NULL;
}

void Merge(struct node *p,struct node *q){
struct node *last=NULL;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p!=NULL && q!=NULL ){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL){
    last->next=p;
    }
    else{
    last->next=q;
    }
    Display(first);
}
bool is_loop(struct node *f){
    struct node *p,*q;
    p=q=f;
    do{
    p=p->next;
    q=q->next;
    q=q!=NULL?q->next:NULL;
    }while(p && q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }

}




int main()
{
int arr[]={10,20,50,60};
create(arr,4);
int arr2[]={11,30,50,60,70};
create2(arr2,5);
cout<<boolalpha<<is_loop(first)<<endl;
Merge(first,second);
// concatination(first,second);
// Reverse1(first);
// Reverse2(first);
// Reverse3(NULL,first);
// Remove_Duplicates(first);
// cout<<boolalpha;
// cout<<"The link-list is sorted:"<<sorted(first)<<endl;
// cout<<"The deleted element is:"<<Delete(first,4)<<endl;
// Insert(first,2,0);
// Sortedinsert(first,25);
// Display(third);
// Display(second);
// cout<<"The elements of linked list(using recursion) are:"<<endl;
// rdisplay(first);
// cout<<"The number of nodes in linked list(using loop) is:"<<count(first)<<endl;
// cout<<"The number of nodes in linked list(using recursion) is:"<<rcount(first)<<endl;
// cout<<"The sum of all the elements of linked list(using loop) is:"<<add(first)<<endl;
// cout<<"The sum of all the elements of linked list(using recursion)is:"<<radd(first)<<endl;
// cout<<"The maximum of all the elements of linked list(using loop) is:"<<maxi(first)<<endl;
// cout<<"The maximum of all the elements of linked list (using recursion) is:"<<rmaxi(first)<<endl;
// cout<<find(first,5)<<endl;
// cout<<rfind(first,5)<<endl;
}
