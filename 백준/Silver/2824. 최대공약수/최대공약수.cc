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
#define INF 1000000000

using namespace std;

vector<long long> A, B;
int N, M;
long long inp;

long long llGCD(long long a, long long b) {
	long long tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	
	if (a % b == 0) return b;
	return llGCD(b, a % b);
}

int main()
{
	bool overINF = false;
	long long ans = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &inp);
		A.push_back(inp);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%lld", &inp);
		B.push_back(inp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			long long gcd = llGCD(A[i], B[j]);
			if (gcd > 1) {
				// 두 수의 최대 공약수는 이미 곱했으므로 나눠서 제거
				A[i] /= gcd;
				B[j] /= gcd;
			}

			ans *= gcd;

			if (ans >= INF) {
				ans %= INF;
				overINF = true;
			}
		}
	}

	if (overINF) printf("%09lld", ans);
	else printf("%lld", ans);

	return 0;
}