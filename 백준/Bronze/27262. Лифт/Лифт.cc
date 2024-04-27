#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    scanf("%d %d %d %d", &n, &k, &a, &b);
    printf("%d %d", abs(1 - k) * b + (n - 1) * b, (n - 1) * a);
    return 0;
}