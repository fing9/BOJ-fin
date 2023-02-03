#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int N, S;
vector<int> arr;
int answer=0;

void solve(int now, int sum, bool is_start)
{
    for(int i=now;i<N;i++) // 모든 경우의 수 조사
    {
        solve(i+1,sum+arr[i],false);
    }
    
    if(sum==S && is_start==false) // 기저상태
        answer++;
    
    return;
}

int main()
{
    int num;
    scanf("%d %d",&N,&S);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        arr.push_back(num);
    }
    
    sort(arr.begin(),arr.end());
    
    solve(0,0,true);
    
    printf("%d",answer);
    
    return 0;
}