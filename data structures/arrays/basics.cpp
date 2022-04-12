#include<iostream>
#include<bits/stdc++.h>

using namespace std;


//Increase the size of array 

int main()
{
    int *p=new int[5];
    for(int i=0,j=2;i<5,j<12;i++,j+=2){
        p[i]=j;
        cout<<p[i]<<endl;
    }

    int *q=new int[10];
    for (int i=0;i<5;i++){
        q[i]=p[i];
    }
    delete []p;
    p=q;
    q=nullptr;
    for(int i=0;i<6;i++){
        cout<<p[i]<<endl;
    }
}

// Creating 2-D arrays
// Method-1
// int main()
// {
//     int *a[3];
//     a[0]=new int[4];
//     a[1]=new int[4];
//     a[2]=new int[4];
//     for(int i=0;i<3;i++){
//         for(int j=0;j<4;j++){
//             cout<<a[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }

// Method-2
// int main()
// {
//     int **a;
//     a=new int*[3];
//     a[0]=new int[4];
//     a[1]=new int[4];
//     a[2]=new int[4];
//     for(int i=0;i<3;i++){
//         for(int j=0;j<4;j++){
//             cout<<a[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }

