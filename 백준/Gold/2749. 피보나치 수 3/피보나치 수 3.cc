#include <iostream>
#include <vector>
#include <cstdio>
#define N 2
using namespace std;
long long MOD = 1000000;
long long num;

vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b)
{
    vector<vector<long long>> ret(N, vector<long long>(N, 0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int l=0;l<N;l++)
            {
                ret[i][j] += (a[i][l]*b[l][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    
    return ret;
}

vector<vector<long long>> solve(vector<vector<long long>> &a, vector<vector<long long>> &v, long long sq)
{
    vector<vector<long long>> temp(N, vector<long long>(N, 0));
    if(sq==1) // 1일 때 원본 행렬을 곱함
    {
        return v;
    }
    else if(sq%2==0) // 짝수일 때 제곱근을 제곱 함 (A^(n/2))^2
    {
        temp = solve(a, v, sq/2);
        return mul(temp, temp);
    }
    else // 홀수일 때 한 번 제곱함 (A^n)*(A)
    {
        temp = solve(a, v, sq-1);
        return mul(temp, a);
    }
}

int main()
{
    scanf("%lld",&num);
    vector<vector<long long>> v(N, vector<long long>(N, 0));
    vector<vector<long long>> arr(N, vector<long long>(N, 0));
    if(num==1)
    {
        printf("1");
        return 0;
    }
    else if(num==2)
    {
        printf("1");
        return 0;
    }
    
    arr[0][0]=1;
    arr[0][1]=1;
    arr[1][0]=1;
    arr[1][1]=0;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            v[i][j] = arr[i][j];
        }
    }
    
    v = solve(arr, v, num-1);
    
    printf("%lld",v[0][0]%MOD);
    
    return 0;
}