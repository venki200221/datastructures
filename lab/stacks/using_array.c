#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *s;
};
void create(struct Stack *st){
    printf("Enter the Size of the stack:\n");
    scanf("%d",&(st->size));
    printf("%d",st->size);
    st->top=-1;
    st->s=calloc(st->size,sizeof(int));
}

void Display(struct Stack *st){
    for(int i=st->size;i>=0;i--){
        printf("%d\n",st->s[i]);
    }
}

void Push(struct Stack *st,int x ){
 
if(st->top==st->size-1){
    printf("stack overflow");
}
else{
    st->top++;
    st->s[st->top]=x;
}
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        return -1;
    }
    else{
        x=st->s[st->top];
        st->top--;
        return x;
    }
}
int StackTop(struct Stack st){
    if(st.top==-1){
        return -1;
    }
    else{
        return st.s[st.top];
    }
}

int peek(struct Stack st,int pos){
    int x=-1;
    if (st.top-pos+1<0)
    {
        printf("invalid position");
    }
    else{
        x=st.s[st.top-pos+1];
    }
    return x;
}

int main(){
    struct Stack sa;
    create(&sa);
    Push(&sa,10);
    Push(&sa,20);
    Display(&sa);
}
