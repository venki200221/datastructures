#include <iostream>
#include <time.h>
// #include <bits/stdc++.h>
using namespace std;

int partition(int Array[],int start,int end){
    int pivot = Array[start];
    int count = 0;

    for (int i = start+1; i <= end; i++)
    {
        if (Array[i]<=pivot)
        {
            count+=1;
        }
    }

    int pivotIndex = start + count;
    swap(Array[pivotIndex],Array[start]);

    int i = start,j=end;

    while (i<pivotIndex && j>pivotIndex)
    {
        while (Array[i]<=pivot)
        {
            i++;
        }
        
        while (Array[j]>pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(Array[i++], Array[j--]);
        }
    }
    return pivotIndex;
}

void quicksort(int Array[],int start,int end){
    if(start>=end)
    return;

    int p = partition(Array,start,end);
    quicksort(Array,start,p-1);
    quicksort(Array,p+1,end);
}

void display(int Array[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<Array[i]<<"   ";
    }
    
}

int main(){
    int n;
    time_t start,end;
    cout<<"Enter the size: ";
    cin>>n;
    int a[n];
    
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%n;
    }
    start = clock();
    quicksort(a,0,n-1);
    end = clock();
    
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Time taken: "<<fixed<<time_taken<<setprecision(5);
    cout<<"sec"<<endl;
    cout<<"The sorted Arrayay is: ";
    display(a,n);
    return 0;
    
}