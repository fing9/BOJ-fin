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

ll fact[21], rankRet = 0;
vector<ll> v, retComb, bsV;
ll N, inp, cmd;

ll factorial(ll cur) {
	// base case
	if (fact[cur] != 0) return fact[cur];
	if (cur == 1 || cur == 0) return fact[cur] = 1;

	return fact[cur] = cur * factorial(cur - 1);
}

void getComb(vector<ll> retV, vector<ll> bsV, ll rank, ll pSumRank, ll cnt) {
	if (cnt == N) {
		for (int i = 0; i < retV.size(); i++) {
			printf("%lld ", retV[i]);
		}
		return;
	}

	ll i;
	for (i = 1; i <= N; i++) {
		if (binary_search(bsV.begin(), bsV.end(), i)) continue;

		if (rank < pSumRank + fact[N - cnt - 1]) break;
		else if (rank > pSumRank + fact[N - cnt - 1]) pSumRank += fact[N - cnt - 1];
		else break;
	}

	retV.push_back(i);
	bsV.push_back(i);
	sort(bsV.begin(), bsV.end());

	getComb(retV, bsV, rank, pSumRank, cnt + 1);
}

void getRank() {

	for (ll i = 0; i < N; i++) {
		for (ll j = 1; j < v[i]; j++) {
			bool flag = false;
			for (ll k = 0; k < i; k++) {
				if (v[k] == j) {
					flag = true;
					break;
				}
			}
			if (flag) continue;
			rankRet += fact[N - i - 1];
		}
	}

	printf("%lld", rankRet + 1);
}

int main()
{
	for (ll i = 0; i < 21; i++) {
		factorial(i);
	}

	scanf("%lld", &N);
	scanf("%lld", &cmd);

	if (cmd == 1) {
		scanf("%lld", &inp);
		getComb(retComb, bsV, inp, 0, 0);
	}
	else {
		for (ll j = 0; j < N; j++) {
			scanf("%lld", &inp);
			v.push_back(inp);
		}
		getRank();
	}

	return 0;
}