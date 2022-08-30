#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void swapping(int &a, int &b) {     
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {   
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {    
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
    int n;
    time_t start,end;
    cout<<"Enter the size: ";
    cin>>n;
    int a[n];
    for(int i = 0; i <n ; i++){
        a[i] = rand()%n;
    }
    cout<<"The array is: ";
    display(a,n);
    cout<<endl;
    
    start = clock();
    mergeSort(a,0,n-1);
    end = clock();
    
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    
    cout<<"Time take: "<<fixed<<time_taken<<setprecision(5);
    cout<<"sec"<<endl;
    cout<<"The sorted array is: ";
    display(a,n);
    return 0;
}
