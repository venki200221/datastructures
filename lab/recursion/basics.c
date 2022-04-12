#include<stdio.h>
#include<stdlib.h>


// void TOH(int n,int A,int B,int C){
//     if(n>0){
//         TOH(n-1,A,C,B);
//         printf("( %d , %d)\n",A,C);
//         TOH(n-1,B,A,C);
//     }
// }
// int main(){
// TOH(4,1,2,3);
// }

// factorial
// int fact(int n){
//     if(n<=1){
//         return 1;
//     }
//     else{
//         return n*fact(n-1);
//     }
// }

// int main(){
//     printf("%d",fact(5));
// }



// maximum and minimum
// int n=3;

// int maxi(int arr[]){
     
//     static int i=0,maxim=-9999;
//     if(i<n){
//       if(arr[i]>maxim)
//      maxim=arr[i];
      
//       i++;
//       maxi(arr);
//     }
//     return maxim;
// }

// int mini(int arr[]){
//     static int i=0,minim=+99999;
//     if(i<n){
//         if(arr[i]<minim){
//             minim=arr[i];
//         }
//         i++;
//         mini(arr);
//     }
//     return minim;
// }


// int main(){
//     int a[]={1,3,5};
//    printf("%d", maxi(a));
//    printf("%d", mini(a));

// }


// binary search

int binary(int arr[],int l,int r,int x){
    if(r>=l){
    int mid=(l+(r-1))/2;

    if(arr[mid]==x){
         return mid;
    }
    if(arr[mid]>x){
        return binary(arr,l,mid-1,x);
    }
    else{
        return binary(arr,mid+1,r,x);
    }
    }
    return -1;
}

int main(){
int arr[]={2,3,4,5,6};
int n=sizeof(arr)/sizeof(arr[0]);
if(binary(arr,0,n-1,10)!=-1){
printf("hi");
}
}