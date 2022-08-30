#include<iostream>
#include<stdio.h>
#include<string.h>

#define Sizes 256

int table [Sizes];

void shifttable(char p[25]){
int i,m;
m=strlen(p);
for(int i=0;i<Sizes;i++){
    table[i]=m;
}
for(int i=0;i<=m-2;i++){
    table[p[i]]=m-i-1;
}
}

int hoorsepool(char t[100],char p[25]){
    int m,n,k,i;
    m=strlen(p);
    n=strlen(t);
    i=m-1;
    while(i<n-1){
       k=0;
       while (k<m && p[m-1-k]==t[i-k]){
           k=k+1;
           if(k==m){
            return i-m+1;
           }
           else{
            i=i+table[t[i]];
           }
       }
      
       
    }
    return -1;
}