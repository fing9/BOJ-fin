#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321
#define ll long long

using namespace std;

int main() {
    int n;
    long long ret = 2;

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        ret += ret - 1;
    }
    printf("%lld", ret * ret);

    return (0);
}