#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, x, ret = 0;

    scanf("%d\n%d", &n, &x);
    while(n--) {
        int p1, p2, p3;
        scanf("%d %d", &p1, &p2);
        if(abs(p1-p2) <= x) ret += max(p1, p2);
        else {
            scanf("%d", &p3);
            ret += p3;
        }
    }

    printf("%d", ret);
    return 0;
}
