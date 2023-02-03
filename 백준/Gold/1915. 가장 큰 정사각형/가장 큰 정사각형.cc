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

int matrix[1002][1002];
int DP[1002][1002];
int n, m, ans = 0;
char c;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &c);
			matrix[i][j] = c - '0';
			if (matrix[i][j] == 1) {
				DP[i][j] = min(min(DP[i - 1][j], DP[i][j - 1]), DP[i - 1][j - 1]) + 1;
			}
			else {
				DP[i][j] = 0;
			}
			ans = max(ans, DP[i][j]);
		}
	}

	printf("%d", ans*ans);

	return 0;
}