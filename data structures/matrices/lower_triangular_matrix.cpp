#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct matrix{
    int *arr;
    int n{};
};

void Set(struct matrix *m,int i,int j,int x){
if(i>=j){
    m->arr[(i*(i-1)/2)+(j-1)]=x;
}
}

int Get(struct matrix m,int i,int j){    
if(i>=j){
    return  m.arr[(i*(i-1)/2)+(j-1)];
}
else{
    return 0;
}
}
void Display(struct matrix m){
    for(int i=1;i<m.n;i++){
        for(int j=1;j<m.n;j++){
            if(i>=j){
                cout<<m.arr[(i*(i-1)/2)+(j-1)]<<" ";
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

cout<<"Enter the dimension of matrix"<<endl;
cin>>m.n;
m.arr=new int[((m.n)*(m.n+1))/2];
int x{};
for(int i=0;i<m.n;i++){
    for(int j=0;j<m.n;j++){
        cin>>x;
        Set(&m,i,j,x);
    }
}

Display(m);

}