#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N, ret=-10000;
vector<int> arr, arr2;
int pickedNum[8]={0,0,0,0,0,0,0,0};

int Calculate(vector<int>& v)
{
    int resert=0;
    for(int i=0;i<v.size()-1;i++)
    {
        resert += abs(v[i] - v[i+1]);
    }
    
    return resert;
}

void BackTracking(int n, vector<int>& picked, int toPick)
{
    // 기저 사례
    if(toPick==0){ ret=max(ret,Calculate(picked)); return; }
    for(int next=0;next<arr.size();next++)
    {
        if(pickedNum[next]==0)
        {
            picked.push_back(arr[next]);
            pickedNum[next]=1;
            BackTracking(n,picked,toPick-1);
            picked.pop_back();
            pickedNum[next]=0;
        }
    }
    return;
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        int num;
        scanf("%d",&num);
        arr.push_back(num);
    }
    
    BackTracking(0,arr2,N);
    
    printf("%d",ret);
    
    return 0;
}