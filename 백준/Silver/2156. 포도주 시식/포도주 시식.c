# include <stdio.h>
int is_case=0;

int Max(int X, int Y, int Z)
{
    if(X>=Y && X>=Z)
        return X;
    else if(Y>=X && Y>=Z)
        return Y;
    else
        return Z;
}

int main()
{
    int N, arr[10001], DP[10001], i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&arr[i]);
    
    DP[0] = 0;
    DP[1] = arr[1];
    if(N!=1)
        DP[2] = arr[1] + arr[2];
    else
    {
        printf("%d",DP[1]);
        return 0;
    }
    if(N==2)
    {
        printf("%d",DP[2]);
        return 0;
    }
    for(i=3;i<=N;i++)
    {
        DP[i] = Max(DP[i-1], DP[i-2]+arr[i], DP[i-3]+arr[i-1]+arr[i]);
    }
    
    printf("%d",DP[N]);
    return 0;
}