#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <cmath>
#define INF 19876543210

using namespace std;

int q[1000001];
long long numQ[1000001];
int head = 0, rear = 0;
int idx = 0;
stack<long long> st;

long long NUM(long long num);
long long POP();
long long INV();
long long DUP();
long long SWP();
long long ADD();
long long SUB();
long long MUL();
long long DIV();
long long MOD();
void clearSt();

int input();
void program(long long X);

int main()
{
	int N, ret;
	long long X;

	while (1) {
		head = 0;
		rear = 0;
		idx = 0;
		ret = input();
		if (ret == 0) return 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			clearSt();
			scanf("%lld", &X);
			program(X);
		}
		getchar();
		printf("\n");
	}

	return 0;
}

int input() {
	long long X;
	char cmd[10];

	while (1) {
		scanf("%s%*c", cmd);

		if (cmd[0] == 'N') { // NUM X
			scanf("%lld%*c", &X);
			q[rear++] = 1;
			numQ[idx++] = X;
		}
		else if (cmd[0] == 'P') { // POP
			q[rear++] = 2;
		}
		else if (cmd[0] == 'I') { // INV
			q[rear++] = 3;
		}
		else if (cmd[0] == 'D' && cmd[1] == 'U') { // DUP
			q[rear++] = 4;
		}
		else if (cmd[0] == 'S' && cmd[1] == 'W') { // SWP
			q[rear++] = 5;
		}
		else if (cmd[0] == 'A') { // ADD
			q[rear++] = 6;
		}
		else if (cmd[0] == 'S') { // SUB
			q[rear++] = 7;
		}
		else if (cmd[0] == 'M' && cmd[1] == 'U') { // MUL
			q[rear++] = 8;
		}
		else if (cmd[0] == 'D') { // DIV
			q[rear++] = 9;
		}
		else if (cmd[0] == 'M' && cmd[1] == 'O') { // MOD
			q[rear++] = 10;
		}
		else if (cmd[0] == 'E'){ // END
			break;
		}
		else { // QUIT
			return 0;
		}

	}
	return 1;
}

void program(long long X) {
	long long ret;
	int s = head, e = rear, nIdx = 0;

	st.push(X);

	while (s < e) {
		int cmd = q[s++];
		
		switch (cmd)
		{
			case 1:
				ret = NUM(numQ[nIdx++]);
				break;
			case 2:
				ret = POP();
				break;
			case 3:
				ret = INV();
				break;
			case 4:
				ret = DUP();
				break;
			case 5:
				ret = SWP();
				break;
			case 6:
				ret = ADD();
				break;
			case 7:
				ret = SUB();
				break;
			case 8:
				ret = MUL();
				break;
			case 9:
				ret = DIV();
				break;
			case 10:
				ret = MOD();
				break;
		}

		if (ret == -INF) {
			return;
		}
	}

	if (st.size() != 1) {
		printf("ERROR\n");
		return;
	}

	printf("%lld\n", st.top());
	return;
}

long long NUM(long long num) {
	st.push(num);

	return num;
}

long long POP() {
	if (st.empty()) {
		printf("ERROR\n");
		return -INF;
	}

	long long ret = st.top();
	st.pop();
	return ret;
}

long long INV() {
	if (st.empty()) {
		printf("ERROR\n");
		return -INF;
	}

	long long cur = st.top();
	st.pop();
	cur = -cur;
	st.push(cur);

	return st.top();
}

long long DUP() {
	if (st.empty()) {
		printf("ERROR\n");
		return -INF;
	}

	st.push(st.top());

	return st.top();
}

long long SWP() {
	if (st.size() < 2) {
		printf("ERROR\n");
		return -INF;
	}

	long long top1, top2;
	top1 = st.top();
	st.pop();
	top2 = st.top();
	st.pop();
	st.push(top1);
	st.push(top2);

	return st.top();
}

long long ADD() {
	if (st.size() < 2) {
		printf("ERROR\n");
		return -INF;
	}

	long long top1, top2;
	top1 = st.top();
	st.pop();
	top2 = st.top();
	st.pop();

	st.push(top1 + top2);

	if (abs(st.top()) > 1000000000) {
		printf("ERROR\n");
		return -INF;
	}

	return st.top();
}

long long SUB() {
	if (st.size() < 2) {
		printf("ERROR\n");
		return -INF;
	}

	long long top1, top2;
	top1 = st.top();
	st.pop();
	top2 = st.top();
	st.pop();

	st.push(top2 - top1);

	if (abs(st.top()) > 1000000000) {
		printf("ERROR\n");
		return -INF;
	}

	return st.top();
}

long long MUL() {
	if (st.size() < 2) {
		printf("ERROR\n");
		return -INF;
	}

	long long top1, top2;
	top1 = st.top();
	st.pop();
	top2 = st.top();
	st.pop();

	st.push(top1 * top2);

	if (abs(st.top()) > 1000000000) {
		printf("ERROR\n");
		return -INF;
	}

	return st.top();
}

long long DIV() {
	if (st.size() < 2) {
		printf("ERROR\n");
		return -INF;
	}

	long long top1, top2;
	top1 = st.top();
	st.pop();
	top2 = st.top();
	st.pop();

	if (top1 == 0) {
		printf("ERROR\n");
		return -INF;
	}

	long long ret = top2 / top1;
	st.push(ret);

	if (abs(st.top()) > 1000000000) {
		printf("ERROR\n");
		return -INF;
	}

	return st.top();
}

long long MOD() {
	if (st.size() < 2) {
		printf("ERROR\n");
		return -INF;
	}

	long long top1, top2;
	top1 = st.top();
	st.pop();
	top2 = st.top();
	st.pop();

	if (top1 == 0) {
		printf("ERROR\n");
		return -INF;
	}

	int flag = 0;
	if (top2 < 0) flag = 1;

	if (flag == 1)
		st.push(-(abs(top2) % abs(top1)));
	else
		st.push(abs(top2) % abs(top1));

	if (abs(st.top()) > 1000000000) {
		printf("ERROR\n");
		return -INF;
	}

	return st.top();
}

void clearSt() {
	while (!st.empty()) {
		st.pop();
	}
}