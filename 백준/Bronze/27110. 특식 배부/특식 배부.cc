#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main() {
    int n, ret = 0;
    int a[3];
    scanf("%d\n%d %d %d", &n, &a[0], &a[1], &a[2]);

    for (int i = 0; i < 3; i++) {
        if (a[i] < n) {
            ret += a[i];
        } else {
            ret += n;
        }
    }
    
    printf("%d", ret);

    return 0;
}