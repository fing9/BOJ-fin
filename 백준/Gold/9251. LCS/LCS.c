# include <stdio.h>

int max(int X, int Y)
{
    if(X>=Y)
        return X;
    else
        return Y;
}

int main()
{
    int DP[1001][1001], N1, N2, i=1, j=1;
    char arr1[1001], arr2[1001];
    
    arr1[0]=NULL;
    arr2[0]=NULL;
    
    scanf("%c",&arr1[i]);
    while(arr1[i]!='\n')
    {
        i++;
        scanf("%c",&arr1[i]);
    }
    N1=i-1;
    
    j=1;
    scanf("%c",&arr2[j]);
    while(arr2[j]!=NULL)
    {
        j++;
        scanf("%c",&arr2[j]);
    }
    N2=j-1;
    
    for(i=0;i<=1000;i++)
    {
        for(j=0;j<=1000;j++)
            DP[i][j] = 0;
    }
    
    for(i=1;i<=N1;i++)
    {
        for(j=1;j<=N2;j++)
        {
            if(arr1[i]==arr2[j])
                DP[i][j] = DP[i-1][j-1]+1;
            else
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
        }
    }
    printf("%d",DP[N1][N2]);
    return 0;
}