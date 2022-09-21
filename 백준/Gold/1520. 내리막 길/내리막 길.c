# include <stdio.h>
# include <string.h>
int M, N;
long long DP[502][502], a[502][502];

long long solve(int x, int y, int ex_x, int ex_y)
{
    if(a[ex_x][ex_y]<=a[x][y])
        return 0;
    if(DP[x][y]!=-1 && a[ex_x][ex_y]>a[x][y])
        return DP[x][y];
    if(x==M && y==N && a[ex_x][ex_y]>a[x][y])
        return 1;
    else if(x==M && y==N && a[ex_x][ex_y]<=a[x][y])
        return 0;
    
    return DP[x][y] = solve(x+1,y,x,y) + solve(x,y+1,x,y) + solve(x-1,y,x,y) + solve(x,y-1,x,y);

}

int main()
{
    int i, j, judge=1;
    scanf("%d %d",&M,&N);
    
    for(i=1;i<=N;i++)
    {
        memset(DP[i],-1,sizeof(DP[i]));
        memset(a[i],10000000000,sizeof(a[i]));
    }
    
    for(i=0;i<=501;i++)
    {
        DP[i][0] = 10000000000;
        DP[0][i] = 10000000000;
        a[i][0] = 10000000000;
        a[0][i] = 10000000000;
    }
    
    for(i=1;i<=M;i++)
    {
        for(j=1;j<=N;j++)
            scanf("%lld",&a[i][j]);
    }
    
    solve(1,1,0,0);
    
    if(M==1 && N==1)
        printf("1");
    else if(M==1)
    {
        for(i=2;i<=N;i++)
        {
            if(a[1][i]>=a[1][i-1])
            {
                judge=0;
            }
            if(i==N)
            {
                if(judge==1)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
        }
    }
    else if(N==1)
    {
        for(i=2;i<=M;i++)
        {
            if(a[i][1]>=a[i-1][1])
            {
                judge=0;
            }
            if(i==M)
            {
                if(judge==1)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
        }
    }
    else
        printf("%lld",DP[1][1]);
    
    return 0;
}