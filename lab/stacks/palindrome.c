#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *stack;
int top=-1;
void push(char key){
    top++;
    stack[top]=key;
}
char pop(){
    return stack[top--];
}

int is_palindrome(char str[]){
    int len=strlen(str);
    stack=calloc(len,sizeof(char));
    int i,mid=len/2;
    for(i=0;i<mid;i++){
        push(str[i]);
    }
    if(len%2!=0){
        i++;
    }
    while(str[i]!='\0'){
      char ele=pop();
      if(ele!=str[i]){
          return 0;
      }
      i++;
    }
    return 1;
}

int main(){
    char str[]="hello";
    printf("%d",is_palindrome(str));
}