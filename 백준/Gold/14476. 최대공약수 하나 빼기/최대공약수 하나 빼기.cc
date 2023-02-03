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
#define INF 1987654321

using namespace std;

int N, inp, allGCD;
int retGcd = -1, retK = -1;
int v[1000001];
int plGcd[1000002];
int prGcd[1000002];

int gcd(int a, int b) {
	int tmp;
	if (a < b) {
		tmp = b;
		b = a;
		a = tmp;
	}

	if (a % b == 0) return b;
	else return gcd(b, a%b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &v[i]);
		
		if (i == 1) plGcd[i] = v[i];
		else plGcd[i] = gcd(plGcd[i-1], v[i]);
	}

	for (int i = N; i >= 1; i--) {
		if (i == N) prGcd[i] = v[i];
		else prGcd[i] = gcd(prGcd[i+1], v[i]);
	}

	for (int i = 1; i <= N; i++) {
		int value;

		if (i == 1) {
			value = prGcd[i + 1];
			if (v[1] % value != 0) {
				if (retGcd < value) {
					retGcd = value;
					retK = v[1];
				}
			}
		}
		else if (i == N) {
			value = plGcd[i - 1];
				if (v[N] % value != 0) {
					if (retGcd < value) {
						retGcd = value;
						retK = v[N];
					}
				}
		}
		else {
			value = gcd(plGcd[i - 1], prGcd[i + 1]);
				if (v[i] % value != 0) {
					if (retGcd < value) {
						retGcd = value;
						retK = v[i];
					}
				}
		}
	}

	if (retGcd != -1) printf("%d %d", retGcd, retK);
	else printf("-1");

	return 0;
}