#include<iostream>
#include<bits/stdc++.h>
#include<queue>

using namespace std;
queue<int> q;
int arr[][7]={{0,0,0,0,0,0,0},
                  {0,0,1,1,0,0,0},
                  {0,1,0,0,1,0,0},
                  {0,1,0,0,1,0,0},
                  {0,0,1,1,0,1,1},
                  {0,0,0,0,1,0,1},
                  {0,0,0,0,1,0,0}};

int visited[7]={0};
void BFS(int i){
int u=q.front();
cout<<i<<endl;
visited[i]=1;
q.push(i);
while(!q.empty()){
   q.pop();
    for(int v=1;v<=7;v++){
        if(arr[u][v]==1 && visited[v]==0){
            cout<<v;
            visited[v]=1;
            q.push(v);
        }
    }


}
}


int main()
{
    BFS(1);
    

}