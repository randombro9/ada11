#include <stdio.h>
int n,c[20][20],i,j,visited[20];
void main()
{
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    printf("ENter the cost matrix\n");
    printf("Enter 999 if no direct edges\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        scanf("%d",&c[i][j]);
        visited[i]=0;
    }
    prim();
}
void prim()
{
    int min,b,a,k,count=0,cost=0;
    min=999;
    visited[1]=1;
    while(count<n-1)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(visited[i]&&!visited[j]&&min>c[i][j])
                {
                    min=c[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        printf("%d---->%d=%d\n",a,b,c[a][b]);
        cost+=c[a][b];
        visited[b]=1;
        count++;
    }
    printf("Total cost of Spanning tree is %d",cost);
}
