#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int taken[60]={0,};

void solve(int K, int now, vector<int>& arr, vector<int>& picked, int topick)
{
    if(topick==0)
    {
        for(int i=0;i<6;i++)
            printf("%d ",picked[i]);
        printf("\n");
        return;
    }
    for(int i=now;i<K;i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1;
            picked.push_back(arr[i]);
            solve(K,i+1,arr,picked,topick-1);
            taken[i]=0;
            picked.pop_back();
        }
    }
    return;
}

int main()
{
    int K=1;
    while(K!=0)
    {
        scanf("%d",&K);
        if(K==0)
            break;
        
        for(int i=0;i<60;i++)
            taken[i]=0;
        int num;
        vector<int> arr, picked;
        for(int i=0;i<K;i++)
        {
            scanf("%d",&num);
            arr.push_back(num);
        }
        solve(K,0,arr,picked,6);
        printf("\n");
    }
    
    return 0;
}