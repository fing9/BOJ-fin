#include <iostream>
#include <algorithm>
using namespace std;
int N, M, ret = 1987654321;
int DP[102][10002] = {0,}, arr[102][2] = {0,};
//DP[i][j] : i번째까지 앱을 최적으로 비활성화 했을때 j비용으로 확보할 수 있는 메모리의 최댓값

int main()
{
    scanf("%d %d", &N, &M);
    
    for(int i=1;i<=N;i++)
    {
        scanf("%d", &arr[i][1]);
    }
    
    for(int i=1;i<=N;i++)
    {
        scanf("%d", &arr[i][0]);
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<10001;j++)
        {
            if(j-arr[i][0]>=0) //max(앱을 끄지 않고 넘기기, arr[i][0]의 비용을 쓰기 전의 확보한 데이터의 최댓값 + arr[i][0]비용을 써서 확보하는 데이터값)
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-arr[i][0]] + arr[i][1]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<10001;j++)
        {
            if(DP[i][j] >= M) ret = min(ret, j);
        }
    }
    
    printf("%d", ret);
    
    return 0;
}