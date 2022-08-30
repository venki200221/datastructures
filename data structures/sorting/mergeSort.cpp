#include<iostream>

using namespace std;

void Merge(int A[],int l,int mid,int h){
  int i,j,k;
  i=l;
  j=mid+1;
  k=l;
  int B[40];
  while(i<=mid  && j<=h){
    if(A[i]<A[j]){
        B[i++]=A[i++];
    }
    else{
        B[k++]=A[j++];
    }
  }
  
  for(;i<=mid;i++){
    B[k++]=A[i];
  }
  for (;j<=h;j++)
  {
     B[k++]=A[j];
  }
  for(int i=l;i<=h;i++){
    A[i]=B[i];
  }

}

void mergeSort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}


int main(){
int A[]={10,2,5,20,7};
mergeSort(A,0,4);
for(int i=0;i<4;i++){
    cout<<A[i]<<endl;
}
}