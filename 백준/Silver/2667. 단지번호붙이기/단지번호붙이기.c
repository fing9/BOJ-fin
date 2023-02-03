# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int map[100][100], cheak[100][100], answer[1000]={0,}, l=2;

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    
    return 0;
}

void dfs(int node_x, int node_y)
{
    cheak[node_x][node_y]=1;
    
    if(map[node_x+1][node_y]==1 && cheak[node_x+1][node_y]==0)
    {
        dfs(node_x+1,node_y);
        answer[l]++;
    }
    if(map[node_x][node_y+1]==1 && cheak[node_x][node_y+1]==0)
    {
        dfs(node_x,node_y+1);
        answer[l]++;
    }
    if(map[node_x-1][node_y]==1 && cheak[node_x-1][node_y]==0)
    {
        dfs(node_x-1,node_y);
        answer[l]++;
    }
    if(map[node_x][node_y-1]==1 && cheak[node_x][node_y-1]==0)
    {
        dfs(node_x,node_y-1);
        answer[l]++;
    }
}

int main()
{
    char input[27][27];
    int N, will[1000]={0,}, i, j, k=0;
    
    scanf("%d",&N);
    
    for(i=0;i<=26;i++)
    {
        memset(input[i],NULL,sizeof(input[i]));
        memset(map[i],0,sizeof(map[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N+1;j++)
        {
            scanf("%c",&input[i][j]);
        }
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N+1;j++)
        {
            map[i][j]=input[i][j]-48;
        }
    }
    
    for(i=1;i<=N;i++)
    {
        for(j=2;j<=N+1;j++)
        {
            if(map[i][j]==1 && cheak[i][j]==0)
            {
                dfs(i,j);
                answer[l++]++;
            }
        }
    }
    
    qsort(answer, sizeof(answer)/sizeof(int), sizeof(int), compare);
    
    for(i=0;i<1000;i++)
    {
        if(answer[i]!=0)
            will[k++]=answer[i];
    }
    
    printf("%d\n",k);
    
    for(i=0;i<k;i++)
    {
        printf("%d",will[i]);
        if(i!=k-1)
            printf("\n");
    }
    
    return 0;
}