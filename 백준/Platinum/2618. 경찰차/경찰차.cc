#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <unistd.h>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 1000000001
#define MIN -1000000001
#define ll long long
#define ull unsigned long long
#define GRAPH vector<vector<pair<int, int>>>

using namespace std;

int N, W;
int DP[1001][1001]; // DP[경찰차1이 마지막으로 해결한 사건][경찰차2가 마지막으로 해결한 사건] = 지금까지 사건을 해결하는데 최소 이동거리
vector<pair<int, int>> incident;

void init() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            DP[i][j] = MAX;
        }
    }
    incident.push_back({1, 1});
    incident.push_back({N, N});
}

int calc(pair<int, int> a, pair<int, int> b) {
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

int solve(int curA, int curB) {
    if (curA == W + 1 || curB == W + 1) {return 0;}
    if (DP[curA][curB] != MAX) {return DP[curA][curB];}

    int next = max(curA, curB) + 1;

    int lenAtoNext = calc(incident[curA], incident[next]);
    int lenBtoNext = calc(incident[curB], incident[next]);

    int retA = solve(next, curB) + lenAtoNext;
    int retB = solve(curA, next) + lenBtoNext;

    return DP[curA][curB] = min(retA, retB);
}

void printRoute(int curA, int curB) {
    if (curA == W + 1 || curB == W + 1) {return ;}

    int next = max(curA, curB) + 1;

    int lenAtoNext = calc(incident[curA], incident[next]);
    int lenBtoNext = calc(incident[curB], incident[next]);

    int retA = solve(next, curB) + lenAtoNext;
    int retB = solve(curA, next) + lenBtoNext;

    if (retA < retB) {
        printf("1\n");
        printRoute(next, curB);
    }
    else {
        printf("2\n");
        printRoute(curA, next);
    }
}

int main() {
    scanf("%d\n%d", &N, &W);
    init();
    for (int i = 0; i < W; i++) {
        int y, x;

        scanf("%d %d", &y, &x);
        incident.push_back({y, x});
    }
    printf("%d\n", solve(0, 1));
    printRoute(0, 1);

    return (0);
}
