#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void wap(int &a,int &b){
    int temp=b;
    b=a;
    a=temp;
}


void bubleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;i<j;j--){
            if(arr[j]<arr[j-1]){
              wap(arr[j],arr[j-1]);
            }
        }
    }
}

int bsearch(int arr[],int n,int key){

int low=0,high=n-1,mid=(low+high)/2;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(key<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;





}

int main(){
   
    int n=rand();
    cout<<"size"<<n<<endl;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
        clock_t start, end;
     start=clock();
    bubleSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    cout<<bsearch(a,n,10)<<endl;
    end=clock();
    double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
   cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    
}