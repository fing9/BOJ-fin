# include <stdio.h>
# include <string.h>

int DP[1000001];

void funcX(int origin,int X,int try)
{
    
    if(DP[X] != -1)
    {
        try += DP[X]-1;
        if(DP[origin]>try || DP[origin]==-1)
        {
            DP[origin] = try;
        }
        return;
    }
    else if(X==1)
    {
        if(DP[origin]>try || DP[origin]==-1)
        {
            DP[origin] = try;
        }
        return;
    }
    else
    {
        if(X%3==0) //연산 경우의 수 1
        {
            funcX(origin, X/3, try+1);
            funcX(X/3, X/3, 1);
        }
        
        if(X%2==0) //연산 경우의 수 2
        {
            funcX(origin, X/2, try+1);
            funcX(X/2, X/2, 1);
        }
        
        funcX(origin, X-1, try+1);
        funcX(X-1, X-1, 1); //연산 경우의 수 3
    }
}

int main()
{
    int N;
    
    scanf("%d",&N);
    memset(DP,-1,sizeof(DP));
    funcX(N, N, 0);
    
    printf("%d",DP[N]);
    
    return 0;
}