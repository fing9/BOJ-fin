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
#define DIV 10007
#define ll long long

using namespace std;

ll DP[102][21];
vector<int> v;
int N, inp;

ll solve(int cur, ll sum) {
	// base case
	if (sum < 0 || 20 < sum) return 0;
	if (DP[cur][sum] != -1) return DP[cur][sum];
	if (cur == N - 1) {
		if (sum == v[cur]) return 1;
		else return 0;
	}

	ll ret = 0;
	ret += solve(cur + 1, sum - v[cur]);
	ret += solve(cur + 1, sum + v[cur]);

	return DP[cur][sum] = ret;
}

int main()
{
	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 21; j++) {
			DP[i][j] = -1;
		}
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inp);
		v.push_back(inp);
	}
	
	printf("%lld", solve(1, v[0]));


	return 0;
}