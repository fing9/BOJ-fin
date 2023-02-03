#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define INF 12345678987654321

using namespace std;
vector<vector<pair<long long,long long>>> v(10002);
long long dist[10002][22], ret = INF;
int N, M, K;

void init()
{
    for(int i=0;i<10002;i++) {
        for(int j=0;j<22;j++) {
            dist[i][j] = INF;
        }
    }
}


void dijkstra()
{
    priority_queue<pair<long long, pair<long long, long long>>> pq;
    pq.push({0,{1,0}});
    dist[1][0] = 0;

    while (!pq.empty()) {
        long long cost = -pq.top().first;
        long long cur = pq.top().second.first;
        long long nowK = pq.top().second.second;
        pq.pop();

        //중복길 중 코스트가 작은애만 사용
        if(dist[cur][nowK] < cost) continue;

        for (int i = 0; i < v[cur].size(); i++) {
            long long next = v[cur][i].first;
            long long nCost = cost + v[cur][i].second;

            if (nCost < dist[next][nowK]) {
                dist[next][nowK] = nCost;
                pq.push({-nCost, {next, nowK}});
            }

            if (cost < dist[next][nowK + 1] && nowK + 1 <= K) {
                dist[next][nowK + 1] = cost;
                pq.push({-cost, {next, nowK + 1}});
            }
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    init();

    scanf("%d %d %d", &N, &M, &K);
    for(int i=1;i<=M;i++) {
        long long a, b, d;
        scanf("%lld %lld %lld", &a, &b, &d);
        v[a].push_back({b,d});
        v[b].push_back({a,d});
    }

    dijkstra();

    for(int i=0;i<=K;i++) {
        ret = min(ret, dist[N][i]);
    }

    printf("%lld", ret);

    return 0;
}