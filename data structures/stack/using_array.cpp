#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void Create(struct Stack *st);
void Display(struct Stack st);
void Push(struct Stack *st,int x);
int Pop(struct Stack *st);
int Peek(struct Stack st,int pos);
int StackTop(struct Stack st);
bool isEmpty(struct Stack st);
bool isFull(struct Stack st);



struct Stack{
    int size;
    int top;
    int *s;
};

void Create(struct Stack *st){
cout<<"Enter the size of the stack:"<<endl;
cin>>st->size;
st->top=-1;
st->s=new int[st->size];
}

void Display(struct Stack st){
    for(int i=st.top;i>=0;i--){
    cout<<st.s[i]<<endl;
    }
}

void Push(struct Stack *st,int x){
if(st->top==st->size-1){
    cout<<"Stack overflow"<<endl;
}
else{
    st->top++;
    st->s[st->top]=x;
}
}

int Pop(struct Stack *st){
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

int Peek(struct Stack st,int pos){
int x=-1;
if(st.top-pos+1<0){
cout<<"Invalid position"<<endl;
}
else{
x=st.s[st.top-pos+1];
}
return x;
}

int StackTop(struct Stack st){
    if(st.top==-1){
        return -1;
    }
    else{
        return st.s[st.top];
    }
}

bool isEmpty(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

bool isFull(struct Stack st){
    if(st.top==st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}



int main()
{
    struct Stack st;
    Create(&st);
    
    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    cout<<StackTop(st)<<endl;
    cout<<boolalpha<<isEmpty(st)<<endl;
    cout<<boolalpha<<isFull(st)<<endl;
    
    Display(st);
}