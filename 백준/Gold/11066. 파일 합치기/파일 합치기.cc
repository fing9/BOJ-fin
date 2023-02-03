#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    
    scanf("%d", &T);
    
    while(T--)
    {
        int K;
        int DP[502][502], sum[502]={0,}, arr[502] = {0,};
        
        scanf("%d", &K);
        
        for(int i=1;i<=K;i++)
        {
            scanf("%d", &arr[i]);
            sum[i] = arr[i] + sum[i-1];
        }
        
        for(int i=1;i<=K;i++)
        {
            for(int j=1;i+j<=K;j++)
            {
                DP[j][j+i] = 987654321; // DP배열 사용하는 부분 초기화
                for(int k=j;k<i+j;k++)
                {
                    DP[j][j+i] = min(DP[j][j+i], DP[j][k] + DP[k+1][j+i] + sum[j+i] - sum[j-1]);
                }
            }
        }
        
        printf("%d\n", DP[1][K]);
    }
    
    return 0;
}