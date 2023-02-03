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

int N;
int tree[27][2];

void preOrder(int cur) {
	printf("%c", cur + 'A');
	if (tree[cur][0] != -1) preOrder(tree[cur][0]);
	if (tree[cur][1] != -1) preOrder(tree[cur][1]);
}

void inOrder(int cur) {
	if (tree[cur][0] != -1) inOrder(tree[cur][0]);
	printf("%c", cur + 'A');
	if (tree[cur][1] != -1) inOrder(tree[cur][1]);
}

void postOrder(int cur) {
	if (tree[cur][0] != -1) postOrder(tree[cur][0]);
	if (tree[cur][1] != -1) postOrder(tree[cur][1]);
	printf("%c", cur + 'A');
}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N;  i++) {
		char node, lc, rc;
		scanf("%*c%c %c %c", &node, &lc, &rc);
		if (lc != '.') tree[node - 'A'][0] = lc - 'A';
		else tree[node - 'A'][0] = -1;
		if (rc != '.') tree[node - 'A'][1] = rc - 'A';
		else tree[node - 'A'][1] = -1;
	}

	preOrder(0);
	printf("\n");
	inOrder(0);
	printf("\n");
	postOrder(0);
	printf("\n");

	return 0;
}