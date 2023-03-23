#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321
#define ll long long

using namespace std;

int n, ans;
int v[202];
int DP[202];

void init() {
    for (int i = 0; i < 202; i++) {
        v[i] = 0;
        DP[i] = 1;
    }
}

int main() {

    init();

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (v[i] > v[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, DP[i]);
    }

    printf("%d", n - ans);

    return (0);
}