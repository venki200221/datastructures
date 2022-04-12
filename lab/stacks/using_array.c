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

// #include<stdio.h>
// #include<stdlib.h>
// struct Stack{
// int size;
// int top;
// int *s;
// };

// void Create(struct Stack *p){
//     printf("Enter the size of the Stack:");
//     scanf("%d",&(p->size));
//     p->top=-1;
//     p->s=(int*)calloc(p->size,sizeof(int));
// }

// int Is_empty(struct Stack p){
//    return p.top==-1?1:0;
// }
// int Is_full(struct Stack p){
//     return p.top==p.size-1?1:0;
// }



// void Push(struct Stack *p){
//     int x;
//     printf("Enter the data to be pushed:");
//     scanf("%d",&x);
//     if(Is_full==0){
//         printf("Stack overflow");
//     }
//     else{
//         p->top++;
//         p->s[p->top]=x;
//     }
// }

// void Pop(struct Stack *p){
//     if(Is_empty==1){
//         printf("Stack Underflow");
//     }
//     else{
//         printf("%d\n",p->s[p->top]);
//         p->top--;
//     }
// }

// void Display(struct Stack p){
//     if(Is_empty==1){
//         printf("Stack Under flow");
//     }
//     else{
//         printf("The Elements of Stack are:\n");
//         for(int i=p.top;i>=0;i--){
//             printf("%d\n",p.s[i]);
//         }
//     }
// }

// void StackTop(struct Stack p){
//     if(Is_empty==1){
//         printf("The stack underflow");
//     }
//     else{
//         printf("%d is on the top of the stack",p.s[p.top]);
//     }
    
// }

// int main()
// {
// struct Stack st;
// Create(&st);
// printf("%d\n",Is_full(st));
// Push(&st);
// Push(&st);
// Push(&st);
// Pop(&st);
// Pop(&st);
// StackTop(st);
// Display(st);

// return 0;
// }