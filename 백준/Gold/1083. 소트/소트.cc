#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int N, s, i, now = 0;
    vector<int> ret;
    vector<int> v;

    scanf("%d", &N);
    for(i=0;i<N;i++) {
        int inp;
        scanf("%d", &inp);
        v.push_back(inp);
    }

    scanf("%d", &s);

    int maxN, maxJ;
    for(i=0;i<N;i++) {
        maxN = 0, maxJ = 0;
        for(int j=i;j<=i+s && j<N;j++) {
            if(maxN <= v[j]) {
                maxN = v[j];
                maxJ = j;
            }
        }

        //printf("maxN:%d maxJ:%d\n", maxN, maxJ);

        //printf("maxN:%d maxJ-i:%d s:%d\n", maxN, maxJ - i, s);
        ret.push_back(maxN);
        for(int j=maxJ;j>i;j--) {
            v[j] = v[j-1];
        }
        v[i] = maxN;
        s -= maxJ - i;
    }

    for(i=0;i<N;i++) {
        printf("%d ", ret[i]);
    }

    return 0;
}