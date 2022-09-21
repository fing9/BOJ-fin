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
vector<vector<pair<int,int>>> v(1002);
int dist[1002][1002];
int N, M, X;

void init()
{
    for(int i=0;i<1002;i++) {
        for(int j=0;j<1002;j++) {
            dist[i][j] = INF;
        }
    }
}

void dijkstra()
{
    for(int l=1;l<=N;l++) {
        priority_queue<pair<int, int>> pq;
        pq.push({0, l});
        dist[l][l] = 0;

        while (!pq.empty()) {
            int cost = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            for (int i = 0; i < v[cur].size(); i++) {
                int next = v[cur][i].first;
                int nCost = cost + v[cur][i].second;

                if (nCost < dist[l][next]) {
                    dist[l][next] = nCost;
                    pq.push({-nCost, next});
                }
            }
        }
    }
}

void maxDistanceStudent()
{
    int maxDS = -1;

    for(int i=1;i<=N;i++) {
        maxDS = max(maxDS, dist[i][X] + dist[X][i]);
    }

    printf("%d", maxDS);
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    init();
    scanf("%d %d %d", &N, &M, &X);
    for(int i=0;i<M;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b,c});
    }

    dijkstra();

    maxDistanceStudent();

    return 0;
}
