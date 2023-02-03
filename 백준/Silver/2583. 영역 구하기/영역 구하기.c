# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int map[103][103], cheak[103][103], answer[10001]={0,}, l=0;
int M, N, K;

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

void dfs(int x, int y)
{
    cheak[x][y]=1;
    answer[l]++;
    
    if(map[x-1][y]==0 && cheak[x-1][y]==0)
        dfs(x-1,y);
    if(map[x+1][y]==0 && cheak[x+1][y]==0)
        dfs(x+1,y);
    if(map[x][y-1]==0 && cheak[x][y-1]==0)
        dfs(x,y-1);
    if(map[x][y+1]==0 && cheak[x][y+1]==0)
        dfs(x,y+1);

}

int main()
{
    int x1, y1, x2, y2;
    int i, j, o, p;
    scanf("%d %d %d",&M,&N,&K); //input
    
    for(i=0;i<103;i++) //reset
    {
        memset(map[i],-1,sizeof(map[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    memset(answer,-1,sizeof(answer));
    
    for(i=1;i<=M;i++) //paper
    {
        for(j=1;j<=N;j++)
            map[i][j]=0;
    }
    
    for(i=0;i<K;i++) //input(cut)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(o=y1+1;o<=y2;o++)
        {
            for(p=x1+1;p<=x2;p++)
                map[o][p]=1;
        }
    }
    
    for(i=1;i<=M;i++) //solve
    {
        for(j=1;j<=N;j++)
        {
            if(map[i][j]==0 && cheak[i][j]==0)
            {
                answer[l]=0;
                dfs(i,j);
                l++;
            }
        }
    }
    
    qsort(answer, sizeof(answer) / sizeof(int), sizeof(int), compare); //sort
    
    printf("%d\n",l);
    for(i=0;i<10001;i++) //output
    {
        if(answer[i]!=-1)
            printf("%d ",answer[i]);
    }
    
    return 0;
}