#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct matrix{
    int arr[10];
    int n{};
};

void Set(struct matrix *m,int i,int j,int x){
if(i==j){
    m->arr[i-1]=x;
}
}

int Get(struct matrix m,int i,int j){
    if(i==j){
        return m.arr[i-1];
    }
    else{
        return 0;
    }
}
void Display(struct matrix m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            if(i==j){
                cout<<m.arr[i]<<" ";
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
struct matrix m;
m.n=4;
Set(&m,1,1,97);
Set(&m,2,2,100);
Set(&m,3,3,98);
Set(&m,4,4,99);
cout<<Get(m,2,2)<<endl;
Display(m);





}