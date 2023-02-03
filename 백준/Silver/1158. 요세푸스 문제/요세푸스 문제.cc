#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    vector<int> q;
    int N, K, count=0, p=0, now=1;
    scanf("%d %d",&N,&K);

    for(int i=1;i<=N;i++)
        q.push_back(i);

    printf("<");

    while(count!=N)
    {
        if(now==K)
        {
            printf("%d",q[p++]);
            count++;
            now=1;
            if(count!=N)
                printf(", ");
        }
        else
        {
            q.push_back(q[p++]);
            now++;
        }
    }

    printf(">");

    return 0;
}