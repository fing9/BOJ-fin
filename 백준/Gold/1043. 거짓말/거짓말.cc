#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;
vector<int> know; //know[진실을아는사람]
vector<vector<int>> v(52); //v[i번째파티][파티의구성인원]
int visited[52]; //진실을 아는사람과 같은 파티에 온 사람
int N, M, K, ans = 0;

void init() {
    for(int i=0;i<52;i++) {
        visited[i] = 0;
    }
}

void dfs(int s) {
    for(int i=0;i<v[s].size();i++) {
        visited[v[s][i]] = 1;
    }
}

int solve(int s) {
    for(int i=0;i<v[s].size();i++) {
        if(visited[v[s][i]] != 0) {
            return -1;
        }
    }

    return 1;
}

int main(void) {
    init();

    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    for(int i=0;i<K;i++) {
        int inp;
        scanf("%d", &inp);
        know.push_back(inp);
    }

    for(int i=0;i<M;i++) {
        int L;
        scanf("%d", &L);
        for(int j=0;j<L;j++) {
            int inp;
            scanf("%d", &inp);
            v[i].push_back(inp);
        }
    }

    for(int t=0;t<51;t++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < K; j++) {
                for (int l = 0; l < v[i].size(); l++) {
                    if (v[i][l] == know[j] || visited[v[i][l]] == 1) {
                        dfs(i);
                        j = K;
                        l = v[i].size();
                    }
                }
            }
        }
    }

    for(int i=0;i<M;i++) {
        if(solve(i) != -1) {
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}