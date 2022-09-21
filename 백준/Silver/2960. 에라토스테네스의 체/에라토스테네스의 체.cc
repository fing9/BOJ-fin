#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define INF 1987654321

using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int N, K, cnt = 0, arr[1001] = {0,};
    scanf("%d %d", &N, &K);

    for(int i=2;i<=N;i++)
    {
        arr[i] = i;
    }

    for(int i=2;i<=N;i++) {
        if (arr[i] != 0) {
            for (int j = i; j <= N; j += i) {
                if (arr[j] != 0) {
                    arr[j] = 0;
                    cnt++;
                    if (cnt == K) {
                        printf("%d", j);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
