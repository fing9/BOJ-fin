#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#define INF 1987654321

using namespace std;

int t;
int prime[10001];
int visited[10001]; // 0:not visited, 1:visited

int make_nbr(int a, int b, int c, int d) {
    return (a * 1000) + (b * 100) + (c * 10) + (d);
}

int assemble_nbr(int origin, int digit, int idx) {
    int a = (origin / 1000), b = ((origin / 100) % 10), c = ((origin / 10) % 10), d = (origin % 10); // origin = abcd
    if (idx == 0)
        return make_nbr(digit, b, c, d);
    else if (idx == 1)
        return make_nbr(a, digit, c, d);
    else if (idx == 2)
        return make_nbr(a, b, digit, d);
    else if (idx == 3)
        return make_nbr(a, b, c, digit);
}

int bfs(int s, int e) {
    int a = (e / 1000), b = ((e / 100) % 10), c = ((e / 10) % 10), d = (e % 10); // e = abcd
    int ret = INF; // ret : minimum count
    queue<pair<int, int>> q; // {nbr, cnt}
    q.push({s, 0});
    visited[s] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == e) {
            ret = min(ret, cur.second);
            continue;
        }
        for (int i=0;i<4;i++) {
            for (int j=0;j<10;j++) {
                if (i == 0 && j == 0) continue;
                int next = assemble_nbr(cur.first, j, i);
                if (visited[next] != 1 && prime[next] != 0 && cur.second + 1 <= ret) {
                    q.push({next, cur.second + 1});
                    visited[next] = 1;
                }
            }
        }
    }
    return ret;
}

void prime_init() {
    for(int i=2;i<10000;i++) {
        prime[i] = i;
    }

    for(int i=2;i*i<10000;i++) {
        if (prime[i] == 0)
            continue;
        for(int j=2;i*j<10000;j++) {
            prime[i * j] = 0;
        }
    }
}

void visited_init() {
    for(int i=0;i<10000;i++) {
        visited[i] = 0;
    }
}

int main() {
    prime_init();
    scanf("%d", &t);
    while (t--) {
        int s, e, ret;
        visited_init();
        scanf("%d %d", &s, &e);
        ret = bfs(s, e);
        if (ret == INF)
            printf("Impossible\n");
        else
            printf("%d\n", ret);
    }

    return 0;
}