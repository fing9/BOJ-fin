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
int weight[502][502];
int dist[502];
vector<int> route[502];
int cheak[502];
int N, M;
int S, D;
queue<int> q;

void init()
{
    for(int i=0;i<502;i++) {
        dist[i] = INF;
        cheak[i] = -1;
        route[i].clear();
    }
}

void dijkstra()
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,S});
    dist[S] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        //중복길 중 코스트가 작은애만 사용
        if(dist[cur] < cost) continue;

        for (int i = 0; i < N; i++) {
            if(weight[cur][i] == -1) continue;
            int next = i;
            int nCost = cost + weight[cur][i];

            if (nCost < dist[next]) {
                dist[next] = nCost;
                route[next].clear();
                route[next].push_back(cur);
                pq.push({-nCost, next});
            }
            else if(nCost == dist[next]) { //next노드에 도달하는데 필요한 가중치가 같은 여러 루트가 있는 경우 모든 루트 저장
                route[next].push_back(cur);
            }
        }
    }
}

void bfs()
{
    q.push(D);
    cheak[D] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i=0;i<route[cur].size();i++) {
            int next = route[cur][i];
            weight[next][cur] = -1;

            if(cheak[next] != 1) {
                q.push(next);
                cheak[next] = 1;
            }
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    while(1) {
        scanf("%d %d", &N, &M);
        if(N==0 && M==0) break;
        scanf("%d %d", &S, &D);

        for(int i=0;i<502;i++) {
            for (int j = 0; j < 502; j++) {
                weight[i][j] = -1;
            }
        }

        init();

        for (int i = 1; i <= M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            weight[U][V] = P;
        }

        dijkstra();
        bfs();
        init();
        dijkstra();

        if(dist[D] == INF)
            printf("-1\n");
        else
            printf("%d\n", dist[D]);
    }

    return 0;
}