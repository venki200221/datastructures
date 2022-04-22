#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st){
    printf("Enter the size of the stack:");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=calloc(st->size,sizeof(int));
}

void Push(struct Stack *st,int x){
if(st->top==st->size-1){
    printf("The stack overflow\n");
}
else{
    st->top++;
    st->s[st->top]=x;
}
}
void display(struct Stack *st){
    for(int i=st->top;i>=0;i--){
        printf("%d\n",st->s[i]);
    }
}
int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        printf("The stack is empty");
    }
    else{
     x=st->s[st->top];
     st->top--;
     return x;
    }
}

int stackTop(struct Stack st){
    return st.s[st.top];
}

int peek(struct Stack st,int pos){
    int x=-1;
    if(st.top-pos+1<0){
        printf("Invalid position");
    }
    else{
        x=st.s[st.top-pos+1];
        return x;
    }
}
int main(){
   struct Stack sa;
   create(&sa);
   Push(&sa,10);
   Push(&sa,20);
   Push(&sa,250);
   Push(&sa,30);
   Push(&sa,40);
   peek(sa,2);
   printf("%d has benn deleted\n",pop(&sa));
   printf("The top element is:",stackTop(sa));
   display(&sa);

}