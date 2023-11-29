#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;
int N, M, ans = 2147483647;
bool is_friends[4001][4001];
int v[4001];

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a]++;
        v[b]++;
        is_friends[a][b] = true;
        is_friends[b][a] = true;
    }

    bool is_posible = false;
    for (int i=1;i<=N;i++) {
        for (int j=i+1;j<=N;j++) {
            if (is_friends[i][j]) {
                for (int k = j + 1; k <= N; k++) {
                    if (is_friends[i][k] && is_friends[j][k]) {
                        is_posible = true;
                        ans = min(ans, v[i] + v[j] + v[k] - 6);
                    }
                }
            }
        }
    }
    if (is_posible)
        printf("%d", ans);
    else
        printf("-1");

    return 0;
}
