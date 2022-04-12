#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

class Diagonal{
    private:
    int n;
    int *arr;
    public:
    Diagonal(){
        n=2;
        arr=new int[n];
    }
    Diagonal(int n);
    void Set(int i,int j,int x);
    int Get(int i,int j);
    void Display();
    ~Diagonal(){
        delete []arr;
    }

};
Diagonal::Diagonal(int n){
this->n=n;
arr=new int[n];
}
void Diagonal::Set(int i,int j,int x){
    if(i==j){
        arr[i-1]=x;
    }
}
int Diagonal::Get(int i,int j){
    if(i==j){
        return arr[i-10];
    }
    else{
        return 0;
    }
}
void Diagonal::Display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<arr[i]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
int main(){
    Diagonal d(4);
    d.Set(1,1,98);d.Set(2,2,99);d.Set(3,3,100);d.Set(4,4,97);
    d.Display();
}