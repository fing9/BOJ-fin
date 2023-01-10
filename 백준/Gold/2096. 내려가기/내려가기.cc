#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#define INF 1987654321

using namespace std;

int N;
int map[100001][3];

int maxNow[3];
int minNow[3];
int maxLast[3];
int minLast[3];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}

	maxLast[0] = map[N][0];
	maxLast[1] = map[N][1];
	maxLast[2] = map[N][2];
	for (int i = N - 1; i > 0; i--) {
		maxNow[0] = max(map[i][0] + maxLast[0], map[i][0] + maxLast[1]);
		maxNow[1] = max(map[i][1] + maxLast[0], max(map[i][1] + maxLast[1], map[i][1] + maxLast[2]));
		maxNow[2] = max(map[i][2] + maxLast[1], map[i][2] + maxLast[2]);

		maxLast[0] = maxNow[0];
		maxLast[1] = maxNow[1];
		maxLast[2] = maxNow[2];
	}

	minLast[0] = map[N][0];
	minLast[1] = map[N][1];
	minLast[2] = map[N][2];
	for (int i = N - 1; i > 0; i--) {
		minNow[0] = min(map[i][0] + minLast[0], map[i][0] + minLast[1]);
		minNow[1] = min(map[i][1] + minLast[0], min(map[i][1] + minLast[1], map[i][1] + minLast[2]));
		minNow[2] = min(map[i][2] + minLast[1], map[i][2] + minLast[2]);

		minLast[0] = minNow[0];
		minLast[1] = minNow[1];
		minLast[2] = minNow[2];
	}

	printf("%d %d", max(maxLast[0], max(maxLast[1], maxLast[2])), min(minLast[0], min(minLast[1], minLast[2])));

	return 0;
}
