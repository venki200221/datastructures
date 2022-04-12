#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void arr(int a[],int b[],int size1,int size2){
     int i=0,j=0,k=0;
     int c[size1+size2];
     while(i<size1&& j<size2){
      if(a[i]<b[j]){
      c[k]=a[i];
      k++;i++;
      }
      else if(a[i]>b[j]){
     c[k]=b[j];
     k++;j++;
      }
      else{
          c[k]=a[i];
          k++;i++;j++;
      }
     }
for(int i=0;i<k;i++){
    cout<<c[i]<<endl;
}
}

void intersection(int a[],int b[],int size1,int size2){
    int i=0,j=0,k=0;
    int c[size1+size2];
    while(i<size1 && j<size2){
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
            c[k]=b[j];
            i++;j++;k++;
        }
    }
    for(int i=0;i<k;i++){
        cout<<c[i]<<endl;
    }
}

void difference(int a[],int b[],int size1,int size2){
    int i=0,j=0,k=0;
    int c[size1+size2];
    while(i<size1 && j<size2){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;k++;
        }
        else if(a[i]>b[j]){
            j++;
        }
        else{
         i++;j++;
        }
    }
    for(;i<size1;i++){
        c[k]=a[i];
        k++;
    }
    for(int i=0;i<k;i++){
        cout<<c[i]<<endl;
    }
}



int main()
{
int a[]={2,6,10,15,25};
int b[]={3,6,7,15,20};
int c[10];
// arr(a,b,5,5);
// intersection(a,b,5,5);
difference(a,b,5,5);

return 0;
}