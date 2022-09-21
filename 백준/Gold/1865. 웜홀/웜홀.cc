#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

#define INF 987654321

using namespace std;
int TC, N, M, W, l;
long long road[6000][3];
long long dist[501];

void init()
{
    for(int i=0;i<6000;i++)
    {
        road[i][0] = INF;
        road[i][1] = INF;
        road[i][2] = INF;
    }
    for(int i=0;i<501;i++)
    {
        dist[501] = INF;
    }
    l = 0;
}

bool bellman_ford()
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<l;j++)
        {
            int cur = road[j][0];
            int next = road[j][1];
            int cost = road[j][2];

            if(dist[next] > dist[cur] + cost)
            {
                dist[next] = dist[cur] + cost;
            }
        }
    }


    for(int j=0;j<l;j++)
    {
        int cur = road[j][0];
        int next = road[j][1];
        int cost = road[j][2];

        if(dist[next] > dist[cur] + cost)
        {
            return true;
        }
    }

    return false;
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    scanf("%d", &TC);
    while(TC--)
    {
        init();

        scanf("%d %d %d", &N, &M, &W);
        for(int i=1;i<=M;i++)
        {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            road[l][0] = S;
            road[l][1] = E;
            road[l++][2] = T;
            road[l][0] = E;
            road[l][1] = S;
            road[l++][2] = T;
        }
        for(int i=1;i<=W;i++)
        {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);
            road[l][0] = S;
            road[l][1] = E;
            road[l++][2] = -T;
        }

        if(bellman_ford())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}