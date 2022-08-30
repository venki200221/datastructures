#include<iostream>
// #include<bits/stdc++.h>

using namespace std;
void wap(int &a,int &b){
    int temp;
    temp=b;
    b=a;
    a=temp;
}


void bubble(int arr[],int n){
    int flag=0;
   for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            wap(arr[j],arr[j+1]);
            flag++;
        }
    }
    if(flag==0){
    cout<<"The array is sorted"<<endl;
    return;
   }
   }
   
}



int main(){
   

    int n=4;
    int arr[4]={1,5,6,8};
    // cin>>n;

    // for(int i=0;i<n;i++){
    //  cin>>arr[i];
    // }

   bubble(arr,n);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<",";
   }

  return 0;
}