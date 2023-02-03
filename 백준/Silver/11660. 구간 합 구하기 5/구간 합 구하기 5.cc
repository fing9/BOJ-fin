#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <deque>
#define INF 987654321

using namespace std;

int matrix[1025][1025];
int pSum[1025][1025];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &matrix[i][j]);
			pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + matrix[i][j];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		printf("%d\n", pSum[y2][x2] - pSum[y1-1][x2] - pSum[y2][x1-1] + pSum[y1-1][x1-1]);
	}

	return 0;
}