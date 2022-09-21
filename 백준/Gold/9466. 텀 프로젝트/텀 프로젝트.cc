#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define MAX 100001
using namespace std;
int graph[MAX]={0,}, cheak[MAX]={0,}, answer=0, match=0, match_num=0;

void dfs(int start, int now)
{
    if(start==now)
    {
        cheak[now]=2;
        match=1;
        return;
    }
    if(cheak[graph[now]]==1)
    {
        cheak[graph[now]]=2;
        cheak[now]=2;
        match_num=graph[now];
        match=1;
        return;
    }
    else if(cheak[graph[now]]==0)
    {
        cheak[now]=1;
        dfs(start,graph[now]);
        if(match==1)
        {
            cheak[now]=2;
            if(now==match_num)
            {
                match=0;
                match_num=0;
            }
        }
        else
            cheak[now]=3;
    }
    return;
}

int main()
{
    int T;
    
    scanf("%d",&T);
    while(T--)
    {
        answer=0;
        match=0;
        match_num=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&graph[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(cheak[graph[i]]==0)
            {
                dfs(i,graph[i]);
                match=0;
                match_num=0;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            graph[i]=0;
            if(cheak[i]==2)
            {
                answer++;
                cheak[i]=0;
            }
            else
                cheak[i]=0;
        }
        
        printf("%d\n",n-answer);
    }
    return 0;
}