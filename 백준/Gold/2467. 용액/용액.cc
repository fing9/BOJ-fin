#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <utility>

#define INF 2100000000

using namespace std;

int v[100001];
int n, l, r;
int retL, retR;

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    // solve
    l = 0;
    r = n-1;
    retL = 0;
    retR = n-1;
    
    while(l < r) {
        int curCost = abs(v[l] + v[r]);
        int nextLeftCost = abs(v[l+1] + v[r]);
        int nextRightCost = abs(v[l] + v[r-1]);

        if(curCost < abs(v[retR] + v[retL])) {
            retL = l;
            retR = r;
        }

        if(nextLeftCost < nextRightCost) {
            if(l+1 == r) break;
            l++;
        }
        else {
            if(r-1 == l) break;
            r--;
        }
    }

    printf("%d %d", v[retL], v[retR]);

    return 0;
}