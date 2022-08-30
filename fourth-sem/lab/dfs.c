#include<stdio.h>
#include<time.h>
#include<sys/time.h>
int n,a[10][10],i,j,v[10],count=0;
void dfs(int x)
{
    count++;
    v[x]=count;
    if(v[x]!=0)
        printf("%d\t",x);
    int k;
    for(k=1;k<=n;k++)
        if(a[x][k]==1 && v[k]==0)
            dfs(k);
}
void main()
{
        struct timeval tv1,tv2;
    printf("ENter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix :-\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        v[i]=0;
    printf("\nDFS\n");
     gettimeofday(&tv1,NULL);
    for(i=1;i<=n;i++)
        if(v[i]==0)
            dfs(i);
    gettimeofday(&tv2,NULL);
    printf("Time of DFS=%f microseconds",(double)(tv2.tv_usec-tv1.tv_usec));
}

