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
int N, M;
vector<pair<double, double>> cosmoGod[1001];
vector<pair<pair<int, double>,bool>> v[1001]; //true면 원래있던간선
int visited[1001];

void init() {
    for (int i = 0; i < 1001; i++) {
        visited[i] = 0;
    }
}

double mst_prim(int s) {
    double ret = 0;
    priority_queue<pair<pair<double, int>, bool>> pq; // pair : {간선의 가중치, 노드 번호}
    pq.push({{0, s},true});

    while (!pq.empty()) {
        double cost = -pq.top().first.first;
        int cur = pq.top().first.second;
        bool exist = pq.top().second;
        pq.pop();

        if (visited[cur] == 1) continue;
        visited[cur] = 1;
        if(!exist) ret += cost;

        //printf("%lf %d ret:%lf\n", cost, cur, ret);

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first.first;
            double nCost = v[cur][i].first.second;
            double nExist = v[cur][i].second;

            if (visited[next] == 0)
                pq.push({{-nCost, next}, nExist});
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

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        cosmoGod[i].push_back({A, B});
    }

    for (int i = 1; i <= M; i++) {
        int A, B;
        double dist;
        scanf("%d %d", &A, &B);

        dist = calcDist(cosmoGod[A][0], cosmoGod[B][0]);

        v[A].push_back({{B,0},true});
        v[B].push_back({{A,0},true});
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i != j) {
                //TLE나면 인접행렬로 표현해도됨
                bool isExist = false;
                for(int l=0;l<v[i].size();l++) {
                    if(v[i][l].first.first == j) {
                        isExist = true;
                    }
                }
                if(isExist) continue;

                double dist;

                dist = calcDist(cosmoGod[i][0], cosmoGod[j][0]);

                v[i].push_back({{j,dist},false});
            }
        }
    }

    printf("%.2lf", mst_prim(1));

    return 0;
}