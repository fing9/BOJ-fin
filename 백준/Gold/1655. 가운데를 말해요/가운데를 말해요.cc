#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    int N, x, tmp;
    priority_queue< int,vector<int>,greater<int> > q_min;
    priority_queue<int> q_max;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&x);
        
        if(q_max.size() == q_min.size()) // rule1 : 최대힙의 크기가 최소힙보다 0~1 큼
            q_max.push(x);
        else
            q_min.push(x);
        
        if(q_min.size()!=0) // rule2 : 최대힙의 모든 원소가 최소힙의 모든원소보다 작거나 같음
        {
            if(q_max.top() > q_min.top())
            {
                tmp = q_max.top();
                q_max.pop();
                q_max.push(q_min.top());
                q_min.pop();
                q_min.push(tmp);
            }
        }
        
        printf("%d",q_max.top());
        if(i!=N-1)
            printf("\n");
    }
    
    return 0;
}