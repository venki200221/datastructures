#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
int n{};
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
vector<int>v;
int sum1=0;
for(int i=0;i<n-1;i++){
    sum1=arr[i]+arr[i+1];
    v.push_back(sum1);
    arr[i+1]=sum1;
    
}
int result=v.size()-1;
cout<<v.at(result)<<endl;
}