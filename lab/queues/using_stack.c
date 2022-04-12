#include<stdio.h>
#include<stdlib.h>

int stack1[100],stack2[100];
int top1=-1,top2=-1;

void push(int stack[],int top,int key){
top++;
stack[top]=key;
}
int pop(int stack[],int top){
    return stack[--top];
}
enqueue(int x){
    push(stack1,top1,x);
}
dequeue(){
    int x=-1;
    
}