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

int N, M;
char cmd;
int a, b, w;

int Find(pair<int, int> v[], int x) {
	if (v[x].first == x) return x; // 루트 노드를 만나면 루트 노드의 번호를 반환한다.

	// 루트 노드가 아니라면
	int parentX = Find(v, v[x].first); // 루트 노드를 찾는다. (찾으면서 경로 압축, 루트 노드까지의 합 갱신)
	v[x].second += v[v[x].first].second; // 갱신된 자신의 루트 노드 -> 루트 노드까지의 합을 지금 노드에도 갱신

	return v[x].first = parentX; // 루트 노드를 업데이트한다.
}


void Union(pair<int, int> v[], int a, int b, int w) {
	int rootA = Find(v, a); // a의 루트노드를 찾는다.
	int rootB = Find(v, b); // b의 루트노드를 찾는다.

	// 두 집합의 루트 노드가 같다면 이미 같은 집합이므로 종료한다.
	if (rootA == rootB) return;

	// 두 집합 중 B를 A에 합친다.
	// b의 루트노드와 a의 루트노드의 무게차 = a와 루트노드(rootA)의 무게차 - b와 루트노드(rootB)의 무게차 + a와 b의 무게차(==b와 루트노드의 무게차 - a와 루트노드의 무게차)
	v[rootB].second = (v[a].second - v[b].second) + w; // B의 루트노드부터 A의 루트노드 까지의 값 갱신
	v[rootB].first = rootA; // B의 루트노드를 A에 합친다.
}

bool isUnion(pair<int, int> v[], int a, int b) {
	if (Find(v, a) == Find(v, b)) return true; // 단순히 두 집합의 루트노드를 비교해서 판별한다.
	else return false;
}


int main()
{
	while (1) {
		// initialize
		pair<int, int> v[100001];  // disjointSet {자기 보다 무거운 루트 아무나, 자기와 자기보다 무거운 루트의 무게}

		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			v[i].first = i;
			v[i].second = 0;
		}

		// query set
		for (int i = 0; i < M; i++) {
			scanf("%*c%c", &cmd);
			if (cmd == '!') {
				scanf("%d %d %d", &a, &b, &w);
				Union(v, a, b, w);
			}
			else if (cmd == '?') {
				scanf("%d %d", &a, &b);
				if (!isUnion(v, a, b)) printf("UNKNOWN\n"); // 같은 집합에 있지 않다면 판별 불가능
				else printf("%d\n", v[b].second - v[a].second); // b와 루트노드의 무게차 - a와 루트노드의 무게차 = b와 a의 무게차
			}
		}
	}

	return 0;
}