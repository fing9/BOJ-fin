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

int prime[1000001] = { 0, };
int len;
vector<int> primeV;

int main()
{
	int N = -1;

	for (int i = 2; i <= 1000000; i++) {
		prime[i] = i;
	}

	for (int i = 2; i * i <= 1000000; i++) {
		if (prime[i] == 0) continue;
		for (int j = 2 * i; j <= 1000000; j += i) {
			prime[j] = 0;
		}
	}

	while (1) {
		int b = 0;
		bool flag = false;
		scanf("%d", &N);
		if (!N) return 0;

		for (int i = 2; i <= N; i++) {
			if (prime[i] != 0 && prime[N - i] != 0) {
				printf("%d = %d + %d\n", N, i, N - i);
				flag = true;
				break;
			}
		}

		if (!flag) printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}