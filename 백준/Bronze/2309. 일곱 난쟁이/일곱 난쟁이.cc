#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int q[9], cheak[9]={0,}, answer[7], k=0;

void solve(int now, int picknow, int topick)
{
    if(topick==0)
    {
        if(now==100)
        {
            for(int i=0;i<9;i++)
            {
                if(cheak[i]==1)
                {
                    answer[k++]=q[i];
                }
            }
            return;
        }
        else
        {
            return;
        }
    }
    else if(now>100)
    {
        return;
    }
    else
    {
        for(int i=picknow;i<9;i++)
        {
            if(cheak[i]==0)
            {
                cheak[i]=1;
                solve(now+q[i], 0, topick-1);
                cheak[i]=0;
            }
        }
    }
    return;
}

int main()
{
    for(int i=0;i<9;i++)
        scanf("%d",&q[i]);
    
    solve(0,0,7);
    
    sort(answer,answer+7);
    
    for(int i=0;i<7;i++)
        printf("%d\n",answer[i]);
    
    return 0;
}