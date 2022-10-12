#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, M;
vector<vector<int>> v(1001);
int dist[1001][1001];
int DP[1001];

void init() {
    for(int i=0;i<1001;i++) {
        DP[i] = -1;
        for(int j=0;j<1001;j++) {
            dist[i][j] = INF;
        }
    }
    return;
}

int solve(int now) {
    if(now == 2) return 1;
    if(DP[now] != -1) return DP[now];
    
    int ret = 0;
    for(int i=0;i<v[now].size();i++) {
        if(dist[now][2] > dist[v[now][i]][2]) {
            ret += solve(v[now][i]);
        }
    }
    
    return DP[now] = ret;
}

int main() {
    
    init();
    
    scanf("%d %d", &N, &M);
    
    for(int i=1;i<=N;i++) {
        dist[i][i] = 0;
    }
    
    for(int i=1;i<=M;i++) {
        long long A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        v[A].push_back(B);
        v[B].push_back(A);
        dist[A][B] = C;
        dist[B][A] = C;
    }
    
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    printf("%d", solve(1));
    
    return 0;
}