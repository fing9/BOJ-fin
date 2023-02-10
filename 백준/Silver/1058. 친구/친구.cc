#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int dist[52][52];
int ans = 0, ret;

int main() {
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < n; j++) {
            char c;
            scanf("%c", &c);
            if (c == 'N')
                dist[i][j] = INF;
            else
                dist[i][j] = 1;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ret = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= 2 && i != j) {
                ret++;
            }
        }
        ans = max(ans, ret);
    }

    printf("%d", ans);

    return 0;
}