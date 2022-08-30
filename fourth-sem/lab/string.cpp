
#include<iostream>
#include<time.h>
#include<string.h>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

int search(int n, int m, string ts, string ps)
{
    for(int i=0; i<=n-m; i++)
    {
        int j = 0;
        while(j<m && ps[j]==ts[i+j])
        {
            j = j+1;
        }
        if(j == m)
        return i;
    }
    return -1;
}

int main()
{
    clock_t start, end;
    string ts, ps;
    fstream fin;
    fin.open("input.txt");
    while(getline(fin,ts))
    {
        fin>>ts;
    }
    fin.close();
    cout<<"Pattern string: ";
    cin>>ps;
    int m,n;
    n=ts.length();
    m=ps.length();
    start = clock();
    int k = search(n,m,ts,ps);
    end = clock();
    if(k==-1)
    {
        cout<<"No matching pattern";
    }
    else
    {
        cout<<"Pattern found at "<<k;
    }
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"\nTime taken: "<<fixed<<time_taken;
    cout<<"sec"<<endl;
    return 0;
}

