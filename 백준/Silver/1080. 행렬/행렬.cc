#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int n, m, cnt;
int A[52][52], B[52][52];

void rev(int y, int x) {
    for(int i=y;i<y+3;i++) {
        for(int j=x;j<x+3;j++) {
            A[i][j] = A[i][j] == 0 ? 1 : 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) {
        getchar();
        for(int j=1;j<=m;j++) {
            char inp;
            scanf("%c", &inp);
            A[i][j] = inp - '0';
        }
    }

    for(int i=1;i<=n;i++) {
        getchar();
        for(int j=1;j<=m;j++) {
            char inp;
            scanf("%c", &inp);
            B[i][j] = inp - '0';
        }
    }

    for(int i=1;i<=n-2;i++) {
        for(int j=1;j<=m-2;j++) {
            if(A[i][j] != B[i][j]) {
                rev(i, j);
                cnt++;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(A[i][j] != B[i][j]) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", cnt);
    return 0;
}