#include<iostream>

using namespace std;
 
void wap(int &a,int &b){
    int temp;
    temp=b;
    b=a;
    a=temp;
}


void SelectionSort(int arr[],int n){
    int k=0;
    for(int i=0;i<n-1;i++){
        
        for(int j=k=i;j<n;j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        wap(arr[i],arr[k]);
    
    }
}


int main(){

int arr[]={1,5,3,8};
SelectionSort(arr,4);

for(int i=0;i<4;i++){
    cout<<arr[i]<<",";
}

return 0;

}
