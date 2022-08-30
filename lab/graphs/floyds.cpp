#include<iostream>

using namespace std;

int  mini(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

void floyds(int p[][10],int n){
for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                p[i][j]=0;
            }
            else{
                p[i][j]=mini(p[i][j],(p[i][k]+p[k][j]));
            }
        }
    }
}
}

int main(){
     int p[10][10],w,n,e,u,v,i,j;;
 printf("\n Enter the number of vertices:");
 scanf("%d",&n);
 printf("\n Enter the number of edges:\n");
 scanf("%d",&e);
}
