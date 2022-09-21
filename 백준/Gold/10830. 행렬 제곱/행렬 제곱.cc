#include <iostream>
#include <vector>
#include <cstdio>
#define MOD 1000
using namespace std;
int N;

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> ret(N, vector<int>(N, 0));
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

vector<vector<int>> solve(vector<vector<int>> &a, vector<vector<int>> &v, long long sq)
{
    vector<vector<int>> temp(N, vector<int>(N, 0));
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
    long long B;
    scanf("%d %lld",&N,&B);
    vector<vector<int>> v(N, vector<int>(N, 0));
    vector<vector<int>> arr(N, vector<int>(N, 0));
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&arr[i][j]);
            arr[i][j] %= MOD;
            v[i][j] = arr[i][j];
        }
    }
    
    v = solve(arr, v, B);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d",v[i][j]);
            if(j!=N-1)
                printf(" ");
        }
        if(i!=N-1)
            printf("\n");
    }
    // 아이디어는 금방 생각남.
    // 근데 C++에서 vector을 안써봐서 구현하는데 구글의 도움을 받음.
    // vector사용연습 정도로 생각하면 될 듯싶다.
    // 2차원 배열로 함수 인자 넘기는 방법은 없는지 알아보고 싶음.
    return 0;
}