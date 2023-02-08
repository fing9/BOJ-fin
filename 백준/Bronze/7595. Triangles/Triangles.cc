#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int main() {
    int n;

    do {
        scanf("%d", &n);
        if (n == 0) continue;

        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                printf("*");
            }
            printf("\n");
        }
    } while(n != 0);
    return 0;
}