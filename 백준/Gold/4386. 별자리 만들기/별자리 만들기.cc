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

// MST Prim Algorithm

using namespace std;
int N;
vector<pair<double, double>> star;
vector<pair<int, double>> v[101];
int visited[101];

void init() {
    for (int i = 0; i < 101; i++) {
        visited[i] = 0;
    }
}

double mst_prim(int s) {
    double ret = 0;
    priority_queue<pair<double, int>> pq; // pair : {간선의 가중치, 노드 번호}
    pq.push({0, s});

    while (!pq.empty()) {
        double cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur] == 1) continue;
        visited[cur] = 1;
        ret += cost;

        //printf("%lf %d ret:%lf\n", cost, cur, ret);

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            double nCost = v[cur][i].second;

            if (visited[next] == 0)
                pq.push({-nCost, next});
        }
    }

    return ret;
}

double calcDist(pair<double,double> a, pair<double,double> b) {
    double ret;

    return ret = sqrt(pow(abs(a.first - b.first),2) + pow(abs(a.second - b.second),2));
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    init();

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        double A, B;
        scanf("%lf %lf", &A, &B);
        star.push_back({A, B});
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i != j) {
                double dist;
                dist = calcDist(star[i],star[j]);
                v[i].push_back({j,dist});
            }
        }
    }

    printf("%.2lf", mst_prim(0));


    return 0;
}