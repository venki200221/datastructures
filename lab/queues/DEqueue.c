#include<stdio.h>
#include<stdlib.h>

int size;
int arr[100];
int front=-1;
int rear=-1;

void enqueuefront(int x){
if(front==-1){
    printf("DEQueue overflow");
}
else{
    arr[front]=x;
    front--;
}
}

void enqueuerear(int x){
    if(rear==size-1){
        printf("The DEQueue overflow");
    }
    else{
        rear++;
        arr[rear]=x;
    }
}

int dequeuefront(){
    int x=-1;
    if(front==rear){
        printf("The queue is empty");
    }
    else{
        x=arr[front];
        front++;
    }
    return x;
}

int dequeuerear(){
    int x=-1;
    if(rear==-1){
        printf("The DEQueue underflow");
    }
    else{
        x=arr[rear];
        rear--;
    }
}

void display(){
    for(int i=front+1;i<=rear;i++){
    printf("%d",arr[i]);
    if(i<rear){
      printf("<-");
    }
    }
}


int main(){
printf("Enter the size of the queue");
scanf("%d",&size);
// printf("%d",size);
arr[size]=0;
enqueuerear(10);
enqueuerear(20);
display();
dequeuefront();
dequeuefront();

printf("----------------\n");
enqueuefront(40);
enqueuefront(50);
// dequeuerear();
display();

}