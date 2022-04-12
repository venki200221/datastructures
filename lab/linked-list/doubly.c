// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node *prev;
//     struct node *next;
// }*first=NULL,*last;

// void create(){
//     struct node *t;
//     printf("Enter the number of nodes");
//     int n;
//     scanf("%d",&n);
//     printf("Enter the data of first node");
//     int num;
//     scanf("%d",&num);
//     first=malloc(sizeof(struct node));
//     first->data=num;
//     first->next=first->prev=NULL;
//     last=first;
//     for(int i=0;i<n-1;i++){
//        t=malloc(sizeof(struct node));
//        printf("Enter data:");
//        scanf("%d",&num);
//        t->data=num;
//        t->next=last->next;
//        t->prev=last;
//        last->next=t;
//        last=t;
//        }
//     }

// void display(struct node *p){
//     while(p){
//         printf("%d\n",p->data);
//         p=p->next;
//     }
// }

// void disp(struct node *p){
//     while(p){
//         printf("%d\n",p->data);
//         p=p->prev;
//     }
// }

// void insert(struct node *p,int pos,int key){
//     struct node *t;
//     if(pos==0){
//       t=malloc(sizeof(struct node));
//       t->data=key;
//       t->next=t->prev=NULL;
//       t->next=first;
//       first->prev=t;
//       first=t;
//     }
//     else{
//         for(int i=0;i<pos-1;i++){
//             p=p->next;
//         }
//         t=malloc(sizeof(struct node));
//         t->data=key;
//         t->prev=p;
//         t->next=p->next;
//         if(p->next){
//             p->next->prev=t;
//         }
//         p->next=t;
//          }
// }

// int delete(struct node *p,int pos){
//     struct node *q;
//     q=p;
//     int x;
//     if(pos==1){
//         p=p->next;
//         p->prev=NULL;
//         x=q->data;
//         free(q);
//     }
//     else{
//         for(int i=0;i<pos-1;i++){
//             q=q->next;
//         }
//         q->prev->next=q->next;
//         if(q->next){
//             q->next->prev=q->prev;
//         }
//         x=q->data;
//         free(q);
//     }
//     return x;
// }

// void reverse(struct node *p){
//     struct node *temp;
//     while(p){
//         temp=p->next;
//         p->next=p->prev;
//         p->prev=temp;
//         if(p && p->next){
//             first=p;
//         }
//     }
// }

// int main(){
//     create();
//     display(first);
//     // insert(first,2,100);
//     delete(first,1);
//     // disp(first);
//     // reverse(first);

// }
#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *prev;
int data;
struct node *next;
}*first=NULL;

void Create(int arr[],int n){
    struct node *t,*last;
first=malloc(sizeof(struct node));
first->data=arr[0];
first->prev=first->next=NULL;
last=first;
for(int i=0;i<n;i++){
    t=malloc(sizeof(struct node));
    t->data=arr[i];
    t->next=last->next;
    t->prev=last;
    last->next=t;
    last=t;
}
}

void Display(struct node *p){
    while(p){
        printf("%d \n",p->data);
        p=p->next;
    }
}

int length(struct node *p){
    int count=0;
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
    t=malloc(sizeof(struct node));
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
    t=malloc(sizeof(struct node));
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
    free(q);
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
        free(q);
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

Reverse(first);
Display(first);


}