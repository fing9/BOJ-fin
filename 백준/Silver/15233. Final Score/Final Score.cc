#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <utility>

#define INF 2100000000
#define ll long long

using namespace std;

char A[21][21], B[21][21], C[101][21];
int aSize, bSize, cSize;
int aScore, bScore;

int main() {
    scanf("%d %d %d", &aSize, &bSize, &cSize);

    for(int i=0;i<aSize;i++) {
        getchar();
        scanf("%s", A[i]);
    }
    for(int i=0;i<bSize;i++) {
        getchar();
        scanf("%s", B[i]);
    }
    for(int i=0;i<cSize;i++) {
        getchar();
        scanf("%s", C[i]);
    }

    for(int i=0;i<aSize;i++) {
        for(int j=0;j<cSize;j++) {
            if(!strcmp(A[i], C[j])) aScore++;
        }
    }
    for(int i=0;i<bSize;i++) {
        for(int j=0;j<cSize;j++) {
            if(!strcmp(B[i], C[j])) bScore++;
        }
    }

    if(aScore > bScore) printf("A");
    else if(aScore < bScore) printf("B");
    else printf("TIE");

    return 0;
}