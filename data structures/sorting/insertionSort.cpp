#include<iostream>

using namespace std;

void insertionSort(int arr[],int n){
  for(int i=1;i<n;i++){
    int j=i-1;
    int x=arr[i];
    while(j>-1 && x<arr[j]){
        arr[j+1]=arr[j];
        j--;
    } 
    arr[j+1]=x;
  }
}


int main(){
    int arr[]={1,5,8,2,6};
    insertionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}