#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
const int N=40;

void sum(int *p,vector<int>data){
    for(int i=0;i<data.size();i++){
        *p=*p+data.at(i);
    }
}
inline void display_sum(int accum){
    cout<<"sum is "<<accum<<endl;
}
int main(){
    int i;
    int accum=0;
    vector<int> data;
    for(i=0;i<N;i++){
        data.push_back(i);
    }
    sum(&accum,data);
    display_sum(accum);
    return 0;
}         
