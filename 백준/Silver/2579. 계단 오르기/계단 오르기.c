# include <stdio.h>
int DP[301] = {0,};
int DP2[301] = {0,};

int main()
{
    int N, i, j;
    int stair[301] = {0,};
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&stair[i]);
    
    if(N>4)
    {
        DP[N] = stair[N];
        DP[N-1] = stair[N] + stair[N-1];
        DP[N-2] = stair[N] + stair[N-2];
        DP2[N] = stair[N];
        DP2[N-1] = stair[N] + stair[N-1];
        DP2[N-2] = stair[N] + stair[N-2];
        for(i=N-3;i>=1;i--)
        {
            if(stair[i+1]+DP[i+3] >= DP[i+2])
                DP[i] = stair[i] + stair[i+1] + DP[i+3];
            else
                DP[i] = stair[i] + DP[i+2];
        }
        for(i=N-3;i>=2;i--)
        {
            if(stair[i+1]+DP2[i+3] >= DP2[i+2])
                DP2[i] = stair[i] + stair[i+1] + DP2[i+3];
            else
                DP2[i] = stair[i] + DP2[i+2];
        }
    }
    else if(N==4)
    {
        if(stair[1]+stair[2]+stair[4] >= stair[1]+stair[3]+stair[4])
            printf("%d",stair[1]+stair[2]+stair[4]);
        else
            printf("%d",stair[1]+stair[3]+stair[4]);
        return 0;
    }
    else if(N==3)
    {
        if(stair[1]+stair[3] >= stair[2]+stair[3])
            printf("%d",stair[1]+stair[3]);
        else
            printf("%d",stair[2]+stair[3]);
        return 0;
    }
    else if(N==2)
    {
        printf("%d",stair[1]+stair[2]);
        return 0;
    }
    else if(N==1)
    {
        printf("%d",stair[1]);
        return 0;
    }
    
    if(DP[1]>=DP2[2])
        printf("%d",DP[1]);
    else
        printf("%d",DP2[2]);
    return 0;
}