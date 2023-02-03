#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>
#include <set>
#include <map>
#define INF 1987654321
#define ll long long

using namespace std;

vector<int> colorNumV;

int comb[2501][2501];
double ans, sameColorCnt, curRet;
double M, N, K;

int combination(int c, int k) {
	if (comb[c][k] != 0) return comb[c][k];
	if (c == k || k == 0) return comb[c][k] = 1;
	if (k == 1) return comb[c][k] = c;
	return comb[c][k] = combination(c - 1, k) + combination(c - 1, k - 1);
}

int main()
{
	scanf("%lf", &M);
	for (int i = 0; i < M; i++) {
		int inp;
		scanf("%d", &inp);
		colorNumV.push_back(inp);
		N += inp;
	}
	scanf("%lf", &K);

	for (int i = 0; i < M; i++) {
		if (colorNumV[i] < K) continue;

		curRet = 1.0;
		for (int j = 0; j < K; j++) {
			curRet *= (colorNumV[i] - j) / (N - j);
		}
		ans += curRet;
	}

	
	printf("%.16lf", ans);

	return 0;
}