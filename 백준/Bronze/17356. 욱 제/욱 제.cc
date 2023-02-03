#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    double M, ret, A, B;
    scanf("%lf %lf", &A, &B);
    M = ((B - A) / 400);
    ret = 1 / (1 + pow(10, M));
    printf("%.20lf", ret);

    return 0;
}