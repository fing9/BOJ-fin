#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int N, M, inp;
bool DP[32][40001] = {0,};
vector<int> v, v2;

// DP[i][w] : i번 추까지 사용했을 때, w무게를 만들 수 있는지 여부
void solve(int i, int w)
{
    // 기저조건
    if(i>N || DP[i][w]) return;
    
    DP[i][w] = true;
    // printf("i:%d w:%d v[i]:%d\n", i, w, v[i]);
    solve(i+1, w + v[i]); //i번추를 오른쪽 저울에 올린다.
    solve(i+1, abs(w - v[i])); //i번추를 왼쪽 저울에 올린다.
    solve(i+1, w); //i번추를 올리지 않는다.
    
    return;
}

int main()
{
    scanf("%d", &N);
    
    for(int i=1;i<=N;i++)
    {
        scanf("%d", &inp);
        v.push_back(inp);
    }
    
    scanf("%d", &M);
    
    for(int i=1;i<=M;i++)
    {
        scanf("%d", &inp);
        v2.push_back(inp);
    }
    
    solve(0, 0);
    
    int j;
    for(int i=0;i<M;i++)
    {
        for(j=0;j<=N;j++)
        {
            if(DP[j][v2[i]])
            {
                printf("Y");
                break;
            }
        }
        if(j==N+1) printf("N");
        if(i!=M-1) printf(" ");
    }
    
    return 0;
}