#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int *xp , int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[] , int n)
{
    int i , j , min;

    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for ( j = i + 1 ; i < n; i++)
        {
            if (arr[j] < arr[i])
            {
                min = j;
            }
            swap(&arr[min], &arr[i]);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    n = rand()%1000000;

    int a[n];
    cout<<"Enter  array :";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%10000000;
    }
    
    clock_t start,end;
    start = clock();
    selection_sort(a,n);
    end = clock();

    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"The time taken is :"<<fixed<<time_taken<<setprecision(200);
    cout<<"sec"<<endl;

    cout<<"The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"  ";
    }
    return 0;
}