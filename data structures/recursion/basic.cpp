#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// tail-recursion--------------------output =321
// void fun1(int n){
//     if (n>0){
//         cout<<n<<" "<<endl;
//         fun1(n-1);
//     }
// }
// int main(){
// int n=3;
// fun1(3);
// return 0;
// }

// head recursion----------------------output=123
// void fun2(int n){
// if(n>0){
//     fun2(n-1);
//     cout<<n<<endl;
// }
// }
// int main(){
//     int x=3;
//     fun2(x);
// }

// static & global

// with out static and global
// int fun(int n){
//     if(n>0){
//      return fun(n-1)+n;
//     }
//     return 0;
// }
// int main(){
//     int n=5;
//     int r=fun(n);
//     cout<<r<<endl;   //15

//     int t=fun(n);
//     cout<<t<<endl;     //15
// }

// int x=0;   the effect of both global & static variables will be same 
// int fun(int n){
//     static int x=0;
//     if(n>0){
//         x++;
//      return fun(n-1)+x;
//     }
//     return 0;
// }
// int main(){
//     int n=5;
//     int r=fun(n);
//     cout<<r<<endl;   //25

//     int t=fun(n);
//     cout<<t<<endl;   //50 bcoz value of x will become 5
// }

// tree recursion--------------------output=3,2,1,1,2,1,1,1
// void fun(int n){
//     if(n>0){
//     cout<<n<<endl;
//     fun(n-1);
//     fun(n-1);
//     }
// }
// int main()
// {
//     int s=3;
//     fun(s);
//  return 0;
// }

// indirect recursion
// void fun2(int n);
// void fun1(int n){
//     if(n>0){
//     cout<<n<<endl;
//     fun2(n-1);
//     }
// }
// void fun2(int n){
//     if(n>1){
//     cout<<n<<endl;
//     fun1(n/2);
//     }
// }
// int main(){
//     int s=20;
//    fun1(s);
//    return 0;
// }

// Nested recursion----------------------output=91
int fun(int n){
    if(n>100){
        return n-10;
    }
    else{
        return fun(fun(n+11));
    }
}
int main(){
int n=95;
cout<<fun(n)<<endl;
}