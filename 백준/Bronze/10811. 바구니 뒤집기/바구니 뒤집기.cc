#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int arr[102];

void init() {
    for (int i=0;i<=101;i++) {
        arr[i] = i;
    }
}

int main() {
    int N, M;

    init();

    scanf("%d %d", &N, &M);
    for (int k=0;k<M;k++) {
        int a, b;
        scanf("%d %d", &a, &b);

        for (int i=a;i<=b;i++) {
            for (int j=a;j<=a+b-i-1;j++) {
                int tmp;

                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    for (int i=1;i<=N;i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}