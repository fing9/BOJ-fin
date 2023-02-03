#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int N, K;
    int now=0, prtret=0, count=1;
    scanf("%d %d",&N,&K);
    vector<int> q;
    
    for(int i=1;i<=N;i++)
    {
        q.push_back(i);
    }
    
    printf("<");
    while(prtret!=N)
    {
        if(count==K)
        {
            printf("%d",q[now++]);
            
            if(prtret!=N-1)
                printf(", ");
            
            prtret++;
            count=1;
        }
        else
        {
            q.push_back(q[now++]);
            count++;
        }
    }
    printf(">");
    
    return 0;
}