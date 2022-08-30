#include <iostream>
// #include <bits/stdc++.h>
#include<vector>
using namespace std;



int recursive_SS(int sum, int n, vector<int> &a, vector<int> &v)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (a[n - 1] > sum)
        return recursive_SS(sum, n - 1, a,v);
    else
    {
        if(recursive_SS(sum, n - 1, a,v))
            return true;
        if(recursive_SS(sum - a[n - 1], n - 1, a,v))   
        {
             v[n-1]=1;
             return true;

        }        
           return false;
    }
        
}



int main()
{
   
    cout << "Enter number of ele \n";
    int n;
    cin >> n;
    vector<int> a(n, 0);

   
    for (int i = 0; i < n; i++)
        a[i]=i+1;

    int sum =((n*(n+1))/2);
    if(sum%2==1)
    {
        cout<<"Not possible";
        return 0;
    }   

     vector<int> v(n,-1);

    cout << "\nRecurssion Subset sum  Computing for Sum ..."<<sum/2<<"\n " ;
   
    if( recursive_SS(sum/2, n, a, v))
    {
        cout<<"\n Possible";
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1)
                cout<<" -"<<a[i];
            else
                cout<<" +"<<a[i];
        }
    }


    else
    {
        cout<<"\n Not Possible";
    }

    return 0;
}