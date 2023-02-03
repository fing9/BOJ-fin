#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int N, M;
    char bub[11][11];
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;i++) {
        scanf("%*c");
        for(int j=0;j<M;j++) {
            scanf("%c", &bub[i][j]);
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=M-1;j>=0;j--) {
            printf("%c", bub[i][j]);
        }
        printf("\n");
    }

    return 0;
}