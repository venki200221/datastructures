#include<stdio.h>
char stack[100],a[100],p[100];

int top=-1;

void push(char x){
    top++;
    stack[top]=x;
}
void pop(){
    if(top == -1){
        printf("stack empty");
    }
    else{
        top--;
    }
}

int is_operand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

int precedence(char x){
    if(x=='(' || x==')'){
        return 3;
    }
    else if(x=='*' || x=='/') {
        return 2;
    }
    else if(x=='-'|| x=='+'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int i=0,j=0;
    printf("Enter the expression in infix form");
    scanf("%s",a);
    printf("the expression in the postfix form is:");
    while(a[i]!='\0'){
        if(a[i]=='('){
            push(a[i]);
        }
        else if(a[i]==')'){
            while(stack[top]!='(' && top!=-1){
                p[j++]=stack[top];
                pop();
            }
            pop();
        }
        else if(!is_operand(a[i])){
            if(precedence(a[i])>precedence(stack[top])||stack[top]=='('){
                push(a[i]);
            }
            else{
                p[j++]=stack[top];
                pop();i--;
            }
        }
        else{
            p[j++]=a[i];
        }
        i++;
    }

for(int i=0;p[i]!='\0';i++){
    printf("%c",p[i]);
}
while(top!=-1){
    printf("%c",stack[top]);
    pop();
}
return 0;
}