#include<bits/stdc++.h>
using namespace std;
int count1;
int numberOfPaths(int m, int n)
{
int count[m][n];
for (int i = 0; i < m; i++)
count[i][0] = 1;
for (int j = 0; j < n; j++)
count[0][j] = 1;
for (int i = 1; i < m; i++)
{
for (int j = 1; j < n; j++)
{
count1++;
count[i][j] = count[i-1][j] + count[i][j-1];
}
}
return count[m-1][n-1];
}


int main()
{
    int r;
    cout<<"Enter the dimensions of square:" <<endl;
cin>>r;
    clock_t start, end;
       start=clock();
    cout << numberOfPaths(r, r)<<endl;
         end=clock();
         double time_taken = double(end - start)/double(CLOCKS_PER_SEC);
   cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;


cout<<count1;
return 0;
}