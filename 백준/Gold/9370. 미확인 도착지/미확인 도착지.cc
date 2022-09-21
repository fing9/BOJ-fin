#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;
vector<vector<pair<int,int>>> graph(2002);
int dist[2002][3];

void init()
{
    for(int i=0;i<2002;i++) {
        for(int j=0;j<3;j++)
            dist[i][j] = INF;
        graph[i].clear();
    }
}

void dijkstra(int s, int step)
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,s});
    dist[s][step] = 0;

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur][step] < cost) continue;

        for(int i=0;i<graph[cur].size();i++)
        {
            int next = graph[cur][i].first;
            int nCost = cost + graph[cur][i].second;

            if(nCost < dist[next][step])
            {
                dist[next][step] = nCost;
                pq.push({-nCost,next});
            }
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();

        vector<int> ret;
        int n, m, t;
        int s, g, h;
        int x[102];
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        for(int i=0;i<m;i++) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
            //printf("%d %d\n", a, b);
        }
        for(int i=0;i<t;i++) {
            scanf("%d", &x[i]);
        }

        dijkstra(s,0);
        dijkstra(g,1);
        dijkstra(h,2);

        for(int i=0;i<t;i++){
            //printf("cost:%d  x:%d\n", min(dist[g][0] + dist[h][1] + dist[x[i]][2], dist[h][0] + dist[g][2] + dist[x[i]][1]), x[i]);
            if(dist[x[i]][0] == dist[g][0] + dist[h][1] + dist[x[i]][2] || dist[x[i]][0] == dist[h][0] + dist[g][2] + dist[x[i]][1])
            {
                ret.push_back(x[i]);
            }
        }

        sort(ret.begin(),ret.end());

        for(int i=0;i<ret.size();i++)
        {
            printf("%d", ret[i]);
            if(i != ret.size()-1)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}