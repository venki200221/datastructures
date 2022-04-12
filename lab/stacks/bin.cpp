#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<int>s;
    int n;
    cin>>n;
    while(n)
    {
        int d=n%2;
        s.push(d);
        n/=2;
    }
    while(s.empty()==0)
    {
        cout<<s.top();
        s.pop();
    }

    return 0;
}