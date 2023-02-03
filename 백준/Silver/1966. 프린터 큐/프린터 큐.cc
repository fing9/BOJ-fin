#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int T, N, M, num;
    scanf("%d",&T);
    
    while(T--)
    {
        int now=0, count=0, max=0;
        vector<int> q, q_ipt;
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&num);
            q.push_back(num);
            q_ipt.push_back(num);
        }
        sort(q_ipt.begin(),q_ipt.end());
        while(1)
        {
            if(q[now]==q_ipt.back())
            {
                q_ipt.pop_back();
                count++;
                if(now==M)
                    break;
            }
            else
            {
                q.push_back(q[now]);
                if(now==M)
                    M=q.size()-1;
            }
            now++;
        }
        printf("%d\n",count);
        
    }
    
    return 0;
}