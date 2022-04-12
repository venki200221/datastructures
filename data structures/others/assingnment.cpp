#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n2,n3,n4,n5;
    cin>>n1>>n2>>n3>>n4>>n5;
    int arr1[n1],arr2[n2],arr3[n3],arr5[n4],arr4[n5];
    int maxi=0;
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
        if(arr1[i]>maxi){
            maxi=arr1[i];
        }
    }
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
        if(arr2[i]>maxi){
            maxi=arr2[i];
        }
    }
    for(int i=0;i<n3;i++){
        cin>>arr3[i];
        if(arr3[i]>maxi){
            maxi=arr3[i];
        }
    }
   for(int i=0;i<n4;i++){
        cin>>arr4[i];
        if(arr4[i]>maxi){
            maxi=arr4[i];
        }
    }
    for(int i=0;i<n5;i++){
        cin>>arr5[i];
        if(arr5[i]>maxi){
            maxi=arr5[i];
        }
    }
    cout<<maxi<<endl;
    int hash[maxi]={0};
    for(int i=0;i<n1;i++){
        hash[arr1[i]]++;
    }
    for(int i=0;i<n2;i++){
        hash[arr2[i]]++;
    }
    for(int i=0;i<n3;i++){
        hash[arr3[i]]++;
    }
    for(int i=0;i<n3;i++){
        hash[arr3[i]]++;
    }
    for(int i=0;i<n4;i++){
        hash[arr4[i]]++;
    }
    for(int i=0;i<n5;i++){
        hash[arr5[i]]++;
    }
    int count=0;
    for(int i=1;i<maxi;i++){
      if(hash[i]>=3){
         count++;
      }
    }
    cout<<hash[0]<<endl;
    cout<<count<<endl;
    
}