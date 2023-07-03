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

#define INF 2147483647
#define LLINF 223372036854775807

using namespace std;
int start, endN;
int N, M, l;
long long road[200][3];
long long dist[51];
long long earned[51];
int visited[51];

void init() {
    for (int i = 0; i < 200; i++) {
        road[i][0] = LLINF;
        road[i][1] = LLINF;
        road[i][2] = LLINF;
    }
    for (int i = 0; i < 51; i++) {
        dist[i] = LLINF;
    }
    l = 0;
}

void visited_init() {
    for (int i = 0; i < 51; i++) {
        visited[i] = 0;
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < l; i++) {
            if (road[i][0] == cur) {
                int next = road[i][1];

                if (visited[road[i][1]] == 0) {
                    visited[road[i][1]] = 1;
                    q.push(next);
                }
            }
        }
    }
}

long long bellman_ford() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < l; j++) {
            long long cur = road[j][0];
            long long next = road[j][1];
            long long cost = road[j][2] - earned[next];

            if (dist[next] > dist[cur] + cost) {
                dist[next] = dist[cur] + cost;
            }
        }
    }

    for (int j = 0; j < l; j++) {
        long long cur = road[j][0];
        long long next = road[j][1];
        long long cost = road[j][2] - earned[next];

        if (dist[next] > dist[cur] + cost) {
            int start_to_cur, cur_to_end;
            visited_init();
            bfs(start);
            start_to_cur = visited[cur];
            visited_init();
            bfs(cur);
            cur_to_end = visited[endN];
            if (start_to_cur == 1 && cur_to_end == 1)
                return 0;
        }
    }

    return -1;
}

int main() {
    scanf("%d %d %d %d", &N, &start, &endN, &M);

    init();

    for (int i = 0; i < M; i++) {
        long long S, E, T;
        scanf("%lld %lld %lld", &S, &E, &T);
        road[l][0] = S;
        road[l][1] = E;
        road[l++][2] = T;
    }
    for (int i = 0; i < N; i++) {
        scanf("%lld", &earned[i]);
    }

    dist[start] = -earned[start];

    visited_init();
    bfs(start);
    if(visited[endN] == 0) {
        printf("gg\n");
        return 0;
    }

    if (bellman_ford() != -1) {
        printf("Gee\n");
    }
    else {
        printf("%lld", -dist[endN]);
    }
    return 0;
}