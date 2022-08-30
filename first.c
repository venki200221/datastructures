#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[50];
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create1(){

struct node *t,*q;
printf("Enter the number of nodes \n");
int n;
scanf("%d",&n);
printf("Enter the data of first node \n");

first=malloc(sizeof(struct node));
scanf("%s",first->data);
first->next=NULL;
q=first;

for(int i=0;i<n-1;i++){
    printf("Enter the %d th Data:",i+2);
    t=malloc(sizeof(struct node));
    scanf("%s",t->data);
    t->next=NULL;
    q->next=t;
    q=t;
}
}


int countString(struct node *p){
    int Count=0;
    while(p){
       if(strlen(p->data)==4){
           Count++;
       }
       p=p->next;
    }
    return Count;

}


int main(){
    create1();
    printf("%d",countString(first));
    return 0;
}
