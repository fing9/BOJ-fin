# include <stdio.h>
int map[20][20], N;
int team[20];
int min=1000000000;


int gmin(int x, int y)
{
    if(x<=y)
        return x;
    else
        return y;
}

void solve(int d, int pls1, int pls2, int t1, int t2)
{
    int pls=0;
    if(d==N)
    {
        if(pls1>=pls2)
            min = gmin(min,pls1-pls2);
        else
            min = gmin(min,pls2-pls1);
        return;
    }
    else
    {
        if(t1<N/2)
        {
            team[d]=0;
            for(int i=0;i<d;i++)
            {
                if(team[i]==0)
                {
                    pls+=map[d][i];
                    pls+=map[i][d];
                }
            }
            solve(d+1,pls1+pls,pls2,t1+1,t2);
            pls=0;
        }
        
        if(t2<N/2)
        {
            team[d]=1;
            for(int i=0;i<d;i++)
            {
                if(team[i]==1)
                {
                    pls+=map[d][i];
                    pls+=map[i][d];
                }
            }
            solve(d+1,pls1,pls2+pls,t1,t2+1);
        }
    }
}

int main()
{
    int i, j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            scanf("%d",&map[i][j]);
    }
    
    solve(0,0,0,0,0);
    
    printf("%d",min);
    
    return 0;
}