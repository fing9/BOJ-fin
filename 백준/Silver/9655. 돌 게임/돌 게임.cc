#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int DP[1001][2]; // DP[0][]:미정, DP[1][]:상근 승리, DP[2][]:창영 승리 | DP[][0]:상근 턴, DP[][1]:창영 턴

int main() {
    int N;

    scanf("%d", &N);
    // 상근의 경우
    DP[0][0] = 1; // 특이 케이스
    DP[1][0] = 1;
    DP[2][0] = 2;
    DP[3][0] = 1;
    // 창영의 경우
    DP[0][1] = 2; // 특이 케이스
    DP[1][1] = 2;
    DP[2][1] = 1;
    DP[3][1] = 2;
    // DP
    for (int i=4;i<=N;i++) {
        // 상근이라면
        if (DP[i - 3][1] == 2 && DP[i - 1][1] == 2)
            DP[i][0] = 2;
        else
            DP[i][0] = 1;
        // 창영이라면
        if (DP[i - 3][0] == 1 && DP[i - 1][0] == 1)
            DP[i][1] = 1;
        else
            DP[i][1] = 2;
    }

    if (DP[N][0] == 1)
        printf("SK");
    else
        printf("CY");

    return 0;
}