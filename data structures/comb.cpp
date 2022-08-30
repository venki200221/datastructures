#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
int Count;
int c(int n,int r){
    if(r==0 || n==r){
        return 1;
 }
 else{
     ++Count;
     return c(n-1,r-1)+c(n-1,r);
 }
}
int main(){
clock_t start, end;

int n{},r{};
cout<<"Enter the dimensions of square:" <<endl;
cin>>r;
r=r-1;
n=r+r;
   start=clock();
   cout<<n<<"C"<<r<<"=-=-=-= "<<c(n,r)<<endl;
   end=clock();
   double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
   cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;


cout<<Count;
return 0;
}