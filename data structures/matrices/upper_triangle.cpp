#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct Upper{
    int *arr;
    int n{};
};

void Set(struct Upper *m,int i,int j,int x){
m->arr[j*(j-1)/2+(i-1)]=x;
}

int Get(struct Upper m,int i,int j){
    if(i<=j){
        return m.arr[j*(j-1)/2+(i-1)];
    }
    else{
        return 0;
    }
}

void display(struct Upper m){
for(int i=0;i<m.n;i++){
    for(int j=0;j<m.n;j++){
        if(i<j){
            cout<<m.arr[j*(j-1)/2+(i-1)]<<" ";
        }
        else{
            cout<<"0 "<<endl;
        }
    }
    cout<<endl;
}
}
int main(){
struct Upper m;
int x{};
for(int i=0;i<m.n;i++){
    for(int j=0;j<m.n;j++){
        cin>>x;
        Set(&m,i,j,x);
    }
}
display(m);


}