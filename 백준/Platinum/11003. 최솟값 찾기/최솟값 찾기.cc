#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>
#define INF 1987654321

using namespace std;

deque<pair<int,int>> dq;
int N, L, inp;

int main()
{
    scanf("%d %d", &N, &L);

    for (int i = 0; i < N; i++) {
        scanf("%d", &inp);

        if (dq.size() > 0 && dq.front().second < i - L + 1) dq.pop_front();

        while ((!dq.empty()) && (dq.back().first > inp || dq.back().second < i - L + 1)) {
            dq.pop_back();
        }
        dq.push_back({ inp, i });

        printf("%d ", dq.front());
    }

    return 0;
}