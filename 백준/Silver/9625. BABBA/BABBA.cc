#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int DP_A[46];
int DP_B[46];
int K;

int main() {
    scanf("%d", &K);

    DP_A[1] = 0;
    DP_B[1] = 1;
    for(int i=2;i<=K;i++) {
        DP_A[i] = DP_B[i-1];
        DP_B[i] = DP_A[i-1] + DP_B[i-1];
    }

    printf("%d %d", DP_A[K], DP_B[K]);

    return 0;
}