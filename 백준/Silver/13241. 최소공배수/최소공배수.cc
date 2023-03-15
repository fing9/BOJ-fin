#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321

using namespace std;

long long int gcd(long long int a, long long int b) {
    if (a < b) {
        long long int tmp = a;
        a = b;
        b = tmp;
    }
    if (a % b == 0) return b;
    else return (gcd(b, a % b));
}

long long int lcm(long long int a, long long int b) {
    return ((a * b) / gcd(a, b));
}

int main() {
    long long int a, b;

    scanf("%lld %lld", &a, &b);
    printf("%lld", lcm(a, b));

    return (0);
}