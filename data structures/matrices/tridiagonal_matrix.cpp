#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct Tri{
    int *arr;
    int n{};
};
void Set(struct Tri *m,int i,int j,int x){
    if(i-j==0){
        m->arr[m->n+i-2]=x;
    }
    else if(i-j==1){
        m->arr[i-2]=x;
    }
    else if(i-j==-1){
        m->arr[2*(m->n)+i-2]=x;
    }
}

int Get(struct Tri m,int i,int j){
    if(i-j==0){
      return  m.arr[m.n+i-2];
    }
    else if(i-j==1){
       return m.arr[i-2];
    }
    else if(i-j==-1){
       return m.arr[2*(m.n)+i-2];
    }
    else{
        return 0;
    }
}
 
void Display(struct Tri m){
for(int i=0;i<3*(m.n)-2;i++){
    for(int j=0;j<(3*(m.n)-2);j++){
         if(i-j==0){
      cout<<m.arr[m.n+i-2]<<" ";
    }
    else if(i-j==1){
    cout<<m.arr[i-2]<<" ";
    }
    else if(i-j==-1){
    cout<< m.arr[2*(m.n)+i-2]<<" ";
    }
    else{
    cout<<"0 ";
    }
    }
    cout<<endl;
}
}



int main()
{
struct Tri m;
int x{};
for(int i=0;i<3*(m.n)-2;i++){
    for(int j=0;j<(3*(m.n)-2);j++){
         cin>>x;
         Set(&m,i,j,x);
    }
    
}
Display(m);



}