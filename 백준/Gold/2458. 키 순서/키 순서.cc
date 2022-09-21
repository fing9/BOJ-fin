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

using namespace std;
int N, M, ret[501], ans = 0;
int v[501][501];

void init() {
    for(int i=0;i<501;i++) {
        ret[i] = 1;
        for(int j=0;j<501;j++) {
            v[i][j] = INF;
        }
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    init();

    scanf("%d %d", &N, &M);

    for(int i=0;i<M;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a][b] = 1;
    };

    for(int l = 1; l <= N; l++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == l || j == l) continue;
                if (v[i][l] + v[l][j] < v[i][j]) {
                    v[i][j] = v[i][l] + v[l][j];
                }
            }
        }
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            //(자기보다 키가 큰 사람 || 자기보다 키가 작은 사람) == true : 갯수++
            if(v[i][j] != INF || v[j][i] != INF) {
                ret[i]++;
            }
        }
        if(ret[i] == N) ans++;
    }

//    for(int i=1;i<=N;i++) {
//        printf("%d:%d\n", i, ret[i]);
//    }
    printf("%d", ans);

    return 0;
}
