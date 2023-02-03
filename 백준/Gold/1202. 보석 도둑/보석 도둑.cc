#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <deque>
#include <map>
#define INF 1987654321

using namespace std;

int N, K;
vector<pair<long long, long long>> bV;
vector<long long> bagV;
priority_queue<long long> pq;

int main()
{
	long long m, v, c, ret = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &m, &v);
		bV.push_back({ m, v });
	}

	for (int i = 0; i < K; i++) {
		scanf("%lld", &c);
		bagV.push_back(c);
	}

	sort(bV.begin(), bV.end());
	sort(bagV.begin(), bagV.end());

	
	int idx = 0;
	for (int i = 0; i < K; i++) {
		// 매번 가방에 들어갈 수 있는 보석을 추가로 갱신한다.
		while ((idx < N) && (bV[idx].first <= bagV[i])) {
			pq.push(bV[idx++].second);
		}
		// 지금 넣을 수 있는 보석중 가장 가치가 높은 보석을 지금 가방에 넣는다.
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
		//지금 가방에 들어갈 수 있는 보석은 다음 가방에도 들어갈 수 있다.
	}

	printf("%lld", ret);

	return 0;
}