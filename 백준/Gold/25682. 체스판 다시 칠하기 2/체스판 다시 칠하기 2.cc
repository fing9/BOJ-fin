#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#define INF 1987654321

using namespace std;

char matrix[2001][2001];
int pSumCols1[2001][2001];
int pSumCols2[2001][2001];
int pSumRows1[2001][2001];
int pSumRows2[2001][2001];

int main() {
    int n, m, k;
    int ans = INF, ret1, ret2;

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            scanf("%c", &matrix[i][j]);
            pSumCols1[i][j] = 0;
            pSumCols2[i][j] = 0;
            pSumRows1[i][j] = 0;
            pSumRows2[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (((i % 2 == 0) && (j % 2 == 0) && (matrix[i][j] == 'W')) ||
                ((i % 2 == 0) && (j % 2 == 1) && (matrix[i][j] == 'B')) ||
                ((i % 2 == 1) && (j % 2 == 0) && (matrix[i][j] == 'B')) ||
                ((i % 2 == 1) && (j % 2 == 1) && (matrix[i][j] == 'W'))) {
                pSumCols1[i][j] = pSumCols1[i][j - 1] + 1;
            } else {
                pSumCols1[i][j] = pSumCols1[i][j - 1];
            }
            if (((i % 2 == 0) && (j % 2 == 0) && (matrix[i][j] == 'B')) ||
                ((i % 2 == 0) && (j % 2 == 1) && (matrix[i][j] == 'W')) ||
                ((i % 2 == 1) && (j % 2 == 0) && (matrix[i][j] == 'W')) ||
                ((i % 2 == 1) && (j % 2 == 1) && (matrix[i][j] == 'B'))) {
                pSumCols2[i][j] = pSumCols2[i][j - 1] + 1;
            } else {
                pSumCols2[i][j] = pSumCols2[i][j - 1];
            }
            pSumRows1[i][j] = pSumRows1[i - 1][j] + pSumCols1[i][j];
            pSumRows2[i][j] = pSumRows2[i - 1][j] + pSumCols2[i][j];
        }
    }

    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ans = min(ans, min(pSumRows1[i][j] - pSumRows1[i][j - k] - pSumRows1[i - k][j] + pSumRows1[i - k][j - k], pSumRows2[i][j] - pSumRows2[i][j - k] - pSumRows2[i - k][j] + pSumRows2[i - k][j - k]));
        }
    }

    printf("%d", ans);

    return 0;
}