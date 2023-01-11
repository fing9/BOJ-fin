#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <deque>
#define INF 1987654321

using namespace std;

int N, idx = 0;
int tree[20002];

// root -> left -> right
// left -> right -> root


void postOrder(int s, int e) {
	// base case
	if (s >= e) return;

	// 지금 내가 있는 노드보다 큰 수가 나오면 지금 노드의 오른쪽에 있는 노드이다.
	int i;
	for (i = s + 1; i < e; i++) {
		if (tree[s] < tree[i]) {
			break;
		}
	}

	postOrder(s + 1, i); // [다음 수, 내림차순의 끝] 범위는 지금 노드 기준으로 left 노드
	postOrder(i, e); // [내림차순의 끝+1, 지금 범위의 끝] 범위는 지금 노드 기준으로 right 노드
	printf("%d\n", tree[s]);
}


int main()
{
	int last = INF, node, idx = 0;

	while (scanf("%d", &node) > 0) {
		tree[idx++] = node;
	}

	postOrder(0, idx);

	return 0;
}