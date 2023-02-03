#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <queue>
#define INF 1987654321
#define DIV 11

using namespace std;

bool prime[1000001];
int primeCnt[1000001];
vector<int> primeV;
vector<int> v;
vector<vector<int>> vv(101);
int N, inp;
int ans = 1, ansCnt = 0;

int GCD(int a, int b) {
	int tmp;
	if (a < b) {
		tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0) return b;
	else return GCD(b, a % b);
}

int main()
{
	for (int i = 2; i < 1000001; i++) {
		prime[i] = true;
	}
	for (int i = 2; i < 1000001; i++) {
		if (prime[i] == false) continue;
		else primeV.push_back(i);

		int d = i;
		for (int j = 2; d*j < 1000001; j++) {
			prime[d*j] = false;
		}
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &inp);
		v.push_back(inp);
	}

	for (int i = 0; i < N; i++) {
		int cur = v[i];
		for (int j = 0; primeV[j] <= cur;) {
			if (cur % primeV[j] == 0) {
				vv[i].push_back(primeV[j]);
				cur /= primeV[j];
				primeCnt[primeV[j]]++;
			}
			else {
				j++;
			}
		}
	}

	for (int i = 2; i < 1000001; i++) {
		if (primeCnt[i] > 0) {
			ans *= pow(i, primeCnt[i] / N);
			primeCnt[i] /= N;
		}
	}

	for (int i = 0; i < N; i++) {
		queue<pair<int, int>> q;
		int cnt = 1;
		int ansTmp = ans;

		vv[i].push_back(-1);
		for (int j = 0; j < vv[i].size() - 1; j++) {
			if (vv[i][j] == vv[i][j + 1]) cnt++;
			else {
				if (primeCnt[vv[i][j]] != 0) {
					ansTmp /= pow(vv[i][j], primeCnt[vv[i][j]]);
				}
				q.push({ vv[i][j], cnt});
				cnt = 1;
			}
		}

		bool flag = false;
		for (int i = 0; ansTmp > 1;) {
			if (ansTmp % primeV[i] == 0) {
				ansTmp /= primeV[i];
				if (flag == false) {
					q.push({ primeV[i], 0});
				}

				flag = true;
			}
			else {
				flag = false;
				i++;
			}
		}

		while (!q.empty()) {
			pair<int, int> pop = q.front();
			q.pop();
			ansTmp /= pow(pop.first, primeCnt[pop.first]);
			if(primeCnt[pop.first] > pop.second)
				ansCnt += primeCnt[pop.first] - pop.second;
		}

		// 지금 i번째 수를 이루지 않는데, 다른 수에서 가져와야하는 수의 경우 카운팅이 안되고있는 문제가있음
		// 이 수만 카운팅 해주면 정답
	}

	printf("%d %d", ans, ansCnt);

	return 0;
}