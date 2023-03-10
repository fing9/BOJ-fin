#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define INF 987654321

using namespace std;

char    map[17][17];
int     N = 0;

int main() {
    while (scanf("%s", map[N]) != EOF) {
        N++;
    }

    for (int i=0;i<=15;i++) {
        for (int j=0;j<=N;j++) {
            if (map[j][i] != 0)
                printf("%c", map[j][i]);
        }
    }

    return 0;
}