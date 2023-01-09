#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int dr[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };
int visited[52][52];
int counted[52][52];
int map[52][52];
int n, m, ans = 0;
bool infinite = false;

bool isIn(int y, int x) {
	if (0 < y && y <= n && 0 < x && x <= m && map[y][x] != -1) return true;
	else return false;
}

void dfs(int y, int x, int cnt) {
	if (infinite) return;

	for (int i = 0; i < 4; i++) {
		if (isIn(y + map[y][x] * dr[i][0], x + map[y][x] * dr[i][1]) && counted[y + map[y][x] * dr[i][0]][x + map[y][x] * dr[i][1]] < cnt + 1) {
			if (visited[y + map[y][x] * dr[i][0]][x + map[y][x] * dr[i][1]] == 1) {
				infinite = true;
				return;
			}

			counted[y + map[y][x] * dr[i][0]][x + map[y][x] * dr[i][1]] = cnt + 1;
			visited[y + map[y][x] * dr[i][0]][x + map[y][x] * dr[i][1]] = 1;
			dfs(y + map[y][x] * dr[i][0], x + map[y][x] * dr[i][1], cnt + 1);
			if (infinite) return;
			visited[y + map[y][x] * dr[i][0]][x + map[y][x] * dr[i][1]] = 0;
		}
	}
}

int main() {
	char inp;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			scanf("%c", &inp);
			if (inp == 'H')
				map[i][j] = -1;
			else
				map[i][j] = inp - '0';
		}
	}

	visited[1][1] = 1;
	counted[1][1] = 1;
	dfs(1, 1, 1);

	int cnt2 = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, counted[i][j]);
			//printf("%d", counted[i][j]);
		}
		//printf("\n");
	}


	if (infinite)
		printf("-1");
	else
		printf("%d", ans);


	return 0;
}