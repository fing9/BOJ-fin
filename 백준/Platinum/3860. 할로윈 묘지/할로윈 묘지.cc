#pragma warning(disable:4996)
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

pair<int, pair<int, pair<int, int>>> map[31][31]; // { 0:잔디  1:묘비  2:귀신 구멍, {간선의 무게, {도착y, 도착x}}}
int dist[31][31]; // (0,0)에서 모든 좌표에 대한 최단거리
int direc[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int W, H, G, E, totalVertex;
int X, Y;


bool isIn(int y, int x) {
	if (0 <= y && y <= H && 0 <= x && x <= W ) return true;
	else return false;
}

bool canGo(int y, int x) {
	if (isIn(y, x) && map[y][x].first != 1) return true;
	else return false;
}

bool bellman_ford(int sy, int sx) {
	dist[sy][sx] = 0;

	for (int t = 0; t <= totalVertex; t++) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int cY = i, cX = j;
				if (cY == H - 1 && cX == W - 1) continue;

				if (map[cY][cX].first == 2) { // 귀신 구멍인 경우
					int nY = map[cY][cX].second.second.first;
					int nX = map[cY][cX].second.second.second;
					int nT = map[cY][cX].second.first;

					if (dist[cY][cX] != INF && dist[nY][nX] > dist[cY][cX] + nT) {
                        if (t == totalVertex) return true;
						dist[nY][nX] = dist[cY][cX] + nT;
					}
					continue;
				}
				
				for (int k = 0; k < 4; k++) {
					int nY = cY + direc[k][0];
					int nX = cX + direc[k][1];

					if (canGo(nY, nX)) {
						if (dist[cY][cX] != INF && dist[nY][nX] > dist[cY][cX] + 1) {
                            if (t == totalVertex) return true;
							dist[nY][nX] = dist[cY][cX] + 1;
						}
					}
				}
			}
		}
	}

	return false;
}

void init() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			dist[i][j] = INF;
			map[i][j] = { 0, {1, {1, 1}} };
		}
	}
}

int main()
{
	while (1) {
		// initialize
		scanf("%d %d", &W, &H);
		if (W == 0 && H == 0) break;
		totalVertex = W * H - 1;
		init();

		int x, y;
		scanf("%d", &G);
		for (int i = 0; i < G; i++) {
			scanf("%d %d", &x, &y);
			map[y][x].first = 1;
		}

		int x1, y1, x2, y2, t;
		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &t);
			map[y1][x1].first = 2;
			map[y1][x1].second.first = t;
			map[y1][x1].second.second.first = y2;
			map[y1][x1].second.second.second = x2;
		}

		if (bellman_ford(0, 0)) {
			printf("Never\n");
			continue;
		}

		if (dist[H - 1][W - 1] == INF) printf("Impossible\n");
		else printf("%d\n", dist[H - 1][W - 1]);
	}

	return 0;
}