#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int DP[30][3];

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<30;++i)
    {
        DP[i][0]=0;
        DP[i][1]=0;
        DP[i][2]=0;
    }
    
    for(int i=1;i<=N;++i)
    {
        scanf("%d %d",&DP[i][0],&DP[i][1]);
    }
    
    for(int i=N;i>0;--i)
    {
        if(i+DP[i][0]<=N+1)
            DP[i][2]=max(DP[i+1][2],DP[i+DP[i][0]][2]+DP[i][1]);
        else
            DP[i][2]=DP[i+1][2];
    }
    
    printf("%d",DP[1][2]);
    
    return 0;
}