//https://www.acmicpc.net/problem/1010
#include <iostream>
#include <algorithm>
using namespace std;
int DP[31][31];

int combination(int n, int k)
{
    if(n==k)
        return 1;
    else if(k==1)
        return n;
    else if(DP[n][k]!=-1)
        return DP[n][k];
    else
        return DP[n][k] = combination(n-1,k) + combination(n-1,k-1);
}

int main() {
    int t, N, M;

    for(int i=0;i<31;i++) {
        for(int j=0;j<31;j++) {
            DP[i][j]=-1;
            if(i==j) DP[i][j]=1;
        }
    }

    for(int j=0;j<31;j++) {
        DP[j][1]=j;
    }
    DP[0][1]=1;

    scanf("%d",&t);

    while(t--) {
        int DP[31][31];

        scanf("%d %d",&N,&M);

        printf("%d\n",combination(M,N));
    }

    return 0;
}