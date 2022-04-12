#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// for sorted array

// finding the missing number

// int main(){
//     int arr[]={1,2,3,4,5,6,8,9,10};
//     int sum{};
//     for(int i=0;i<=8;i++){
//         sum+=arr[i];
//     }
//     int s=(10*11)/2;
//     cout<<"The missing element is:"<<s-sum<<endl;
// return 0;
// }


// int main(){
//     int arr[]={6,7,8,9,10,11,13,14,15};
//     int l=6;int h=15;
//     int dif=l-0;
//     for(int i=0;i<9;i++){
//         if(arr[i]-i !=l){
//             cout<<"The missing number is:"<<i+l<<endl;
//             break;
//         }
//     }
// }

// Finding multiple missing numbers
// int main()
// {
//     int arr[]={6,7,9,10,11,12,13,15,17};
//     int l=6,h=17;
//     int dif=l-0;
//     for(int i=0;i<9;i++){
//         if(arr[i]-i!=dif){
//             while(dif<arr[i]-i){
//                 cout<<"The missing number is:"<<dif+i<<endl;
//                 dif++;
//             }
//         }
//     }
//     return 0;
// }


// finding multiplemissing numbers using hash table
// int main()
// {
//     int arr[]={3,2,5,4,6,1,9,10,12};
//     int l=1,h=12;
//     int hash[13]={0};
//     for(int i=0;i<9;i++){
//        hash[arr[i]]++;
//     }
//     cout<<"The missing elements are:"<<endl;
//     for(int i=l;i<h;i++){
//         if(hash[i]==0){
//             cout<<i<<endl;
//         }
//     }
// }


// Finding the repeated number
// int main(){
//     int arr[]={1,2,2,3,4,5,6,6,6,6,7,8};
//     int j=0;
//     for(int i=0;i<11;i++){
//       if(arr[i]==arr[i+1]){
//           j=i+1;
//           while(arr[i]==arr[j]){
//               j++;
//           }
//           cout<<arr[i]<<" is repeated "<<j-i<<" times"<<endl;
//           i=j-1;
//       }
//     }
// }

// int main()
// {
//     int arr[]={1,2,2,3,4,5,6,6,6,6,7,8};
//     int l=1,h=8;
//     int hash[9]={};
//     for(int i=l;i<12;i++){
//         hash[arr[i]]++;
//     }
//     cout<<"The missing elements are:"<<endl;
//    for(int i=l;i<h;i++){
//        if(hash[i]>1){
//         cout<<i<<"is repeated for"<< hash[i]<<"times"<<endl;
//        }
//    }
// }

// unsorted array
// Finding duplicates

// int main(){
//     int arr[]={8,3,6,4,5,8,7,6,9,7};
//     int count=1;
//     int j=0;
//     for(int i=0;i<8;i++){
//         count=1;
//         if(arr[i]!=-1){
//             for(int j=i+1;j<9;j++){
//                 if(arr[i]==arr[j]){
//                      count++;
//                      arr[j]=-1;
//                 }
//             }
//             if(count >1){
//              cout<<arr[i]<<" is repeatedfor "<<count <<" times"<<endl;
//             }
//         }
//     }
// }

// using hash table
// int main()
// {
//     int arr[]={8,3,6,4,5,8,7,6,9,7};
//     int hash[9]={0};
//     for(int i=0;i<10;i++){
//             hash[arr[i]]++;
//     }
//     for(int i=0;i<9;i++){
//         if(hash[i]>1){
//             cout<<i<<"is repeated for"<<hash[i]<<"times"<<endl;
//         }
//     }
// }


// finding number of pairs that sum up to a given number
// for unsorted array
// int main()
// {
//     int arr[]={6,3,8,10,16,7,2,9,14};
//     for(int i=0;i<8;i++){
//         for(int j=i+1;j<9;j++){
//          if(arr[i]+arr[j]==10){
//              cout<<arr[i]<<"+"<<arr[j]<<"= 10"<<endl;
//          }
//         }
//     }
// }

// using hash table
// int main()
// {
//     int arr[]={6,3,8,10,16,7,2,9,14};
//     int hash[10]={0};
//     for(int i=0;i<9;i++){
//         if(arr[i]==i){
//             hash[arr[i]]++;
//         }
//     }
//     for(int i=0;i<9;i++){
//         if(hash[10-arr[i]]!=0){
//             cout<<i<<"+"<<10-arr[i]<<" =10"<<endl;
//         }
//     }
//     return 0;
// }

// for sorted array
// int main()
// {
//     int arr[]={1,3,4,5,6,8,9,10,12,14};
//     int i=0,j=9;
//     while(i<j){
//      if(arr[i]+arr[j]==10){
//          cout<<arr[i]<<"+"<<arr[j]<<"= 10"<<endl;
//          i++;j--;
//      }
//      else if(arr[i]+arr[j]<10){
//          i++;
//      }
//      else{
//          j--;
//      }
//     }
// }

// comparing max and min 
// int main()
// {
//     int arr[]={5,8,3,9,6,10,21,44,52,1,0};
//     int max=5,min=5;
//     for(int i=0;i<11;i++){
//         if(arr[i]<min){
//             min=arr[i];
//         }
//         else if(arr[i]>max){
//             max=arr[i];
//         }
//     }
//     cout<<"the max number is:"<<max<<endl;
//     cout<<"the min number is:"<<min<<endl;
// }
