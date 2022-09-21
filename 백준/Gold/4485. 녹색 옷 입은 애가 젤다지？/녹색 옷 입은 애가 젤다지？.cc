#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define INF 1987654321

using namespace std;
int matrix[802][802];
int dist[802][802];
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int N;

void init()
{
    for(int i=0;i<802;i++) {
        for (int j = 0; j < 802; j++) {
            dist[i][j] = INF;
            matrix[i][j] = -1;
        }
    }
}

bool isIn(int y, int x)
{
    if(0<=x && x<N && 0<=y && y<N)
        return true;
    else
        return false;
}

void dijkstra(int y, int x)
{
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({-matrix[y][x],{y, x}});
    dist[y][x] = matrix[y][x];

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        pair<int,int> cur = pq.top().second;
        pq.pop();

        for(int i=0;i<4;i++)
        {
            pair<int,int> next = {cur.first + direction[i][0], cur.second + direction[i][1]};
            if(!isIn(next.first, next.second)) continue;
            int nCost = cost + matrix[next.first][next.second];

            if(nCost < dist[next.first][next.second])
            {
                dist[next.first][next.second] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int l = 1;
    while(1)
    {
        init();

        scanf("%d", &N);
        if(N == 0) break;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }

        dijkstra(0,0);

        printf("Problem %d: %d\n", l++, dist[N-1][N-1]);
    }

    return 0;
}
