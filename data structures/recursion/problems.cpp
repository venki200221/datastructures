#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// problem-1
// int sum(int n){
    
//         if(n==0){
//             return 0;
//         }
//         else{
//             return sum(n-1)+n;
//         }
//     }
// int main(){
// int n{};
// cout<<"Enter the value upto which sum to be calculated:"<<endl;
// cin>>n;
// cout<<"1+2+3+.............="<<sum(n)<<endl;
// return 0;
// }



// problem-2
// int fact(int n){
//     if(n<=1){
//         return 1;
//     }
//     else{
//         return fact(n-1)*n;
//     }
// }
// int main(){
//     int n{};
//     cout<<"Enter the value of n:"<<endl;
//     cin>>n;
//     cout<<"factorial("<<n<<")="<<fact(n)<<endl;
// }

// problem-3
// int power(int m,int n){
//     if(n==0){
//         return 1;
//     }
//     else{
//         return power(m,n-1)*m;
//     }
// }
// int power(int m,int n){
//     if(n==0){
//         return 1;
//     }
//     else if(n%2==0){
//     return power(m*m,n/2);
//     }
//     else{
//     return m*(power(m*m,(n-1)/2));
//     }
// }
// int main(){
//     int m{},n{};
//     cout<<"Enter the number u want to find the power-"<<endl;
//     cin>>m;
//     cout<<"Enter the power to which te number should be raised-"<<endl;
//     cin>>n;
//     cout<<m<<"^"<<n<<":->"<<power(m,n)<<endl;
//     return 0;
// }

// problem-4
// Method-1
// double e(int x,int n){
//     static double p=1,f=1;
    
//     if(n==0){
//         return 1;
//     }
//     else{
//         double r=e(x,n-1);
//         p=p*x;
//         f=f*n;
//         return r+p/f;
//     }
// }

// method-2
// double e(int x,int n){
//     static double s=1;
//     if(n==0){
//         return s;
//     }
//     else{
//         s=1+x*s/n;
//         return e(x,n-1);
//     }
// }

// Method-3
// double e(int x,int n){
//     double s=1;
//     double p=1;
//     double f=1;
//     for(int i=1;i<=n;i++){
//     p=x*p;
//     f=f*i;
//     s=s+p/f;
//     }
//     return s;
// }

// int main()
// {
//     int x{},n{};
//     cout<<"Enter the value of x:"<<endl;
//     cin>>x;
//     cout<<"Enter the value of n:"<<endl;
//     cin>>n;
//     cout<<"1+x/1+x^2/2!+x^3/3!+............="<<e(x,n)<<endl;
// return 0;
// }

// problem-5 --fibanocii series

// Method -1
// int fib(int n){
// if(n<=1){
//     return n;
// }
// else{
//     return fib(n-2)+fib(n-1);
// }
// }

// Method-2
// int fib(int n){
//     int t1=0,t2=1,s=0;
//     if(n<=1){
//         return n;
//     }
//     for(int i=2;i<=n;i++){
//         s=t1+t2;
//         t1=t2;
//         t2=s;
//     }
//     return s;
// }

// method-3--=-=-=-=Memorization method

// int f[100]{-1};
// int fib(int n){
//     if(n<=1){
//         f[n]=n;
//         return n;
//     }
//     else{
//         if(f[n-2]==-1){
//          f[n-2]=fib(n-2);
//         }
//         if(f[n-1]==-1){
//             f[n-1]=fib(n-1);
//         }
//         return fib(n-2)+fib(n-1);
//     }
// }
// int main()
// {
//     int n{};
//     cout<<"Enter the value of n:"<<endl;
//     cin>>n;
//     cout<<"fibanocii("<<n<<") ="<<fib(n)<<endl;
//     return 0;
// }

// problem-6

// int c(int n,int r){
//     if(r==0 || n==r){
//         return 1;
//  }
//  else{
//      return c(n-1,r-1)+c(n-1,r);
//  }
// }
// int main(){
// int n{},r{};
// cout<<"Enter the value of n & r-"<<endl;
// cin>>n>>r;
// cout<<n<<"C"<<r<<"=-=-=-= "<<c(n,r)<<endl;
// return 0;
// }

// Tower of hanoi--problem
// void steps(int n,int A,int B,int C){
//     if(n>0){
//         steps(n-1,A,C,B);
//         cout<<"("<<A<<","<<C<<")"<<endl;
//         steps (n-1,B,A,C);
//     }
// }

// int main(){
// int n{};
// cout<<"Enter the value of n:"<<endl;
// cin>>n;
// steps(n,1,2,3);
// return 0;
// }