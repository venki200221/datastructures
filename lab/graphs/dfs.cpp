#include<iostream>

using namespace std;

int visited[7]={};

int arr[][7]={{0,0,0,0,0,0,0},
                  {0,0,1,1,0,0,0},
                  {0,1,0,0,1,0,0},
                  {0,1,0,0,1,0,0},
                  {0,0,1,1,0,1,1},
                  {0,0,0,0,1,0,1},
                  {0,0,0,0,1,0,0}};

void dfs(int u){
   if(visited[u]==0){
    printf("%d",u);
    visited[u]=1;
    for(int i=0;i<=7;i++){
        if(arr[u][i]==1 && visited[i]==0){
            dfs(i);
        }
    }

   }

}


int main(){
dfs(1);
}