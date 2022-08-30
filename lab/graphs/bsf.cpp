#include<stdio.h>
#include<time.h>

int a[10][10],i,j,n,f=0,r=-1,q[10],visited[10];

void bfs(int v){
    for(int i=1;i<=n;i++){
        if(a[v][i]==1 && visited[i]==0){
            q[++r]=i;
            if(f<=r){
                visited[q[f]]=1;
                bfs(q[f++]);
            }
        }  
    }
}
int  main()
{
    int v;
    
    printf("\nEnter the number of vertives:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    printf("Enter the graph data in form of matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter thr starting vertx:");
    scanf("%d",&v);
        bfs(v);
    printf("\nThe nodes which are reachable are:\n");
    for(i=1;i<=n;i++){
     if(visited[i])
            printf("%d\t",i);
        else
            printf("Bfs is not possible\n");
    }
       
}

