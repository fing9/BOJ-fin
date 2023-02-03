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
    int a, b, c, d, tmp;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    printf("%d", min(a + d,c + b));

    return 0;
}