#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*Head;

void Create(){
    int i;
    struct node *t,*last;
    printf("Enter number of nodes:");
    int n,num;
    scanf("%d",&n);
    printf("Enter the data:");
    scanf("%d",&num);
    Head=malloc(sizeof(struct node));
    Head->data=num;
    Head->next=Head;
    last=Head;
    for(int i=0;i<n-1;i++){
        t=malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&num);
        t->data=num;
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct node *h){
    do{
        printf("%d\n",h->data);
        h=h->next;
    }while(h!=Head);
}

// void rdisplay(struct node *h){
//     static int flag=0;
//     if(h!=Head || h==0){
//         flag=1;
//         printf("%d",h->data);
//         rdisplay(h->next);
//     }
//     flag=0;
// }

void insert(struct node *p,int pos,int x){
    struct node *t;
    if(pos==0){
        t=malloc(sizeof(struct node));
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
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        t=malloc(sizeof(struct node));
        t->data=x;
        t->next=t;
    }
}

int main(){
    Create();
    display(Head);

}