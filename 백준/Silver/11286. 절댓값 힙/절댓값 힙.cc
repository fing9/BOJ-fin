#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    int N, x;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&x);
        if(x==0)
        {
            if(q.size()==0)
            {
                printf("0");
            }
            else
            {
                printf("%d",q.top().second);
                q.pop();
            }
            if(i!=N-1)
                printf("\n");
        }
        else
        {
            q.push({ abs(x), x });
        }
    }
    
    return 0;
}