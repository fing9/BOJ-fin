#include <iostream>
#include <algorithm>
using namespace std;
int dp[21][21][21];

int w(int a, int b, int c)
{
    if(dp[a][b][c]!=-1)
    {
        return dp[a][b][c];
    }
    else if(a<=0 || b<=0 || c<=0)
    {
    	return 1; 
    }
    else if(a>20 || b>20 || c>20)
    {
        return w(20, 20, 20);
    }
    else if(a<b && b<c)
    {
        return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else
    {
        return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
}

int main()
{
    int a, b, c;
    
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<21;j++)
        {
            for(int l=0;l<21;l++)
            {
                dp[i][j][l] = -1;
                if(i==0 || j==0 || l==0)
                {
                    dp[i][j][l] = 1;
                }
            }
        }
    }
    
    while(true)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==-1 && b==-1 && c==-1)
        {
            return 0;
        }
        else if(a<=0 || b<=0 || c<=0)
        {
            printf("w(%d, %d, %d) = %d\n",a,b,c,1);
        }
        else if(a>20 || b>20 || c>20)
        {
            printf("w(%d, %d, %d) = %d\n",a,b,c,w(20,20,20));
        }
        else
        {
            printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
        }
    }
    return 0;
}