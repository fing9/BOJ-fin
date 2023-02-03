#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

#include <utility>
#define PI 3.141592

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    double d1, d2, ret;
    scanf("%lf %lf", &d1, &d2);

    ret = (d1 * 2) + (2 * PI * d2);

    printf("%lf", ret);

    return 0;
}