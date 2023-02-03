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

using namespace std;

vector<int> tmpV;
vector<int> v;
vector<int> cardsV;
int cntV[101];
int visited[101];
int n, k;

int makeSum(vector<int> cards) {
	int ret = 0;

	for (int i = 0; i < k; i++) {
		if (cards[i] < 10) ret *= 10;
		else ret *= 100;
		ret += cards[i];
	}

	return ret;
}

void getCount(vector<int> cards, int cnt) {
	if (cnt == k) {
		cardsV.push_back(makeSum(cards));
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[v[i]] < cntV[v[i]]) {
			visited[v[i]]++;
			cards.push_back(v[i]);
			getCount(cards, cnt+1);
			cards.pop_back();
			visited[v[i]]--;
		}
	}
}

int main()
{
	scanf("%d\n%d", &n, &k);

	for (int i = 0; i < n; i++) {
		int inp;
		scanf("%d", &inp);
		cntV[inp]++;
		v.push_back(inp);
	}

	getCount(tmpV, 0);
	sort(cardsV.begin(), cardsV.end());
	cardsV.erase(unique(cardsV.begin(), cardsV.end()), cardsV.end());

	printf("%d", cardsV.size());

	return 0;
}