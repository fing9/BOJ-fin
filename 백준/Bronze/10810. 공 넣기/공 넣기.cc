#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int arr[101];

int main() {
    int N, M;
    int a, b, c;

    scanf("%d %d" ,&N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        for (int j = a; j <= b; j++) {
            arr[j] = c;
        }
    }

    for (int i=1;i<=N;i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}