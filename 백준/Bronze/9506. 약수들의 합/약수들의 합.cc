#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

int main() {

    do {
        vector<int> v;
        int         N;
        int         sum = 0;

        scanf("%d", &N);
        if (N == -1)
            return (0);
        for (int i=1;i <= N / 2;i++) {
            if (N % i == 0) {
                v.push_back(i);
                sum += i;
            }
        }

        if (sum == N) {
            printf("%d = %d", N, v[0]);
            for (int i=1;i<v.size();i++) {
                printf(" + %d", v[i]);
            }
            printf("\n");
        }
        else {
            printf("%d is NOT perfect.\n", N);
        }

    } while(1);

    return (0);
}