#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first,*second,*third;

void create1(){
    struct node *t,*last;

    printf("Enter the number of nodes:");
    int n;
    scanf("%d",&n);
    printf("Enter the data of 1st node:");
    int num;
    scanf("%d",&num);
    first=malloc(sizeof(struct node));
    first->data=num;
    first->next=NULL;
    last=first;

   for(int i=0;i<n-1;i++){
       printf("Enter the data of %d rd node:",i+2);
       scanf("%d",&num);
       t=malloc(sizeof(struct node));
       t->data=num;
       t->next=NULL;
       last->next=t;
       last=t;
   }
}

void create2(){
    struct node *t,*q;
    printf("Enter the number of nodes:");
    int n;
    scanf("%d",&n);
    second=malloc(sizeof(struct node));
    printf("Enter the data of 1st node:");
    int num;
    scanf("%d",&num);
    second->data=num;
    second->next=NULL;
    q=second;
    for(int i=0;i<n-1;i++){
        printf("Enter the %dth element:",i+2);
        scanf("%d",&num);
        t=malloc(sizeof(struct node));
        t->data=num;
        t->next=NULL;
        q->next=t;
        q=t;
    }
    
}

void display(struct node *p){
    while(p){
        printf("%d \n",p->data);
        p=p->next;
    }
}

void insert(struct node *p,int pos,int key){
struct node *t;
if(first == NULL){
t=malloc(sizeof(struct node));
t->data=key;
t->next==NULL;
first=t;
p=first;
}
if(pos==0){
    t=malloc(sizeof(struct node));
    t->data=key;
    t->next=first;
    first=t;
}
else{
    p=first;
    for(int i=0;i<pos-1 && p;i++){
        p=p->next;
    }
    t=malloc(sizeof(struct node));
    t->data=key;
    t->next=p->next;
    p->next=t;
}
}
void delete(struct node *p,int pos){
    struct node *q=NULL;
    if(pos==1){
     q=first;
     first=first->next;
     printf("%d has been deleted",q->data);
     free(q);
    }
    else{
        for(int i=0;i<pos-1 && p;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        p->next=NULL;
        printf("%d has been deleted",p->data);
        free(p);
    }
}

void rdisplay(struct node *p){
    if(p){
        printf("%d\n",p->data);
        rdisplay(p->next);
    }
}

int count(struct node *p){
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
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
    while(p){
        sum=sum+p->data;
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
    int m=0;
    while(p){
        if(p->data>m){
            m=p->data;
        }
    }
    return m;
}

int rmaxi(struct node *p){
    int x=0;
    if(!p){
        return 0;
    }
    else{
        x=rmaxi(p->next);
        return x>p->data?x:p->data;
    }
}

void sortedInsert(struct node *p,int key){
    struct node *t,*q=NULL;
    t=malloc(sizeof(struct node));
    t->data=key;
    t->next=NULL;
    if(!first){
        first=t;
    }
    else{
        while(p && p->data<key){
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

int sorted(struct node *p){
    int x=-32876;
    while(p){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

struct node *find(struct node *p,int key){
    struct node *q=NULL;
    while(p){
        if(key==p->data){
            return p;
        }
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

void remove_dup(struct node *p){
    struct node *q=p->next;
    while(q){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=q->next;
        }
    }
}

void rev1(struct node *p){
    int qrr[count(first)];
    int i=0;
    while(p){
        qrr[i]=p->data;
        i++;
        p=p->next;
    }
    p=first;
    i--;
    while(p){
        p->data=qrr[i];
        p=p->next;
        i--;
    }
}

void rev2(struct node *p){
    p=first;
    struct node *q,*r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void rev3(struct node *p,struct node *q){
    if(p){
        rev3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}

void concat(struct node *p,struct node *q){
    while(p->next){
        p=p->next;
    }
    p->next=second;
    second=NULL;
}

void merge(struct node *p,struct node *q){
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
    while(p && q){
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
    if(p){
        last->next=p;
    }
    else{
        last->next=q;
    }
    display(first);
}

int main(){
    create1();
    // create2();
    // insert(first,2,30);
    // delete(first,2);
    display(first);
    // display(second);
    // rdisplay(first);
}