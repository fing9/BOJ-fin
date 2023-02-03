#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <queue>

#define INF 1987654321

using namespace std;

queue<int> q;

int main() {
    int N, inp;
    scanf("%d", &N);

    do {
        scanf("%d", &inp);

        if (inp == 0) {
            q.pop();
        } else if (q.size() < N && inp != -1) {
            q.push(inp);
        }
    } while (inp != -1);

    if (q.empty()) {
        printf("empty");
    }
    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop();
    }

    return 0;
}