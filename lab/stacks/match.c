#include<stdio.h>
int a[100],n=10,top=-1;
void push (int x){
 if(top==n-1)
 printf("overflow");
else
{
 top++;
 a[top]=x;
}
}

void pop()
{  if (top==-1)
   printf("underflow");
else
{
  int x=a[top];
  top--;
}}

int main()
{
    
  char s[10]="(())";
  int j=0,ele,e,check=1;
   while(s[j]!='\0')
   { 
       if(s[j]=='('|| s[j]=='['||s[j]=='{')
      { 
          push(s[j]);
          
        }
        
        
        if(s[j]==')'|| s[j]==']'||s[j]=='}')
      { 
    
          if(top!=-1)
        {
             ele=a[top];
             pop();
             e=s[j];
          if(ele==40)
             ele++;
          else 
              ele=ele+2;
          if(e!=ele)
           { check=0;}
        }
        else{
            check=0;
            printf("h");
        }
        }
  
            j++;
        }
        
        
        if(top!=-1)
        check=0;
        
        
        if(check)
        printf("valid");
        else
      printf("invalid");
 

    return 0;
}