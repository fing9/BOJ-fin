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
#define INF 987654321

using namespace std;
int sum[27][200001];
int ret = -1987654321;
int l[27];

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    for(int i=0;i<27;i++) {
        for(int j=0;j<200001;j++) {
            sum[i][j] = 0;
        }
        l[i] = 0;
    }

    int i = 0;
    char c;
    scanf("%c", &c);
    while(c!='\n')
    {
        c -= 'a';
        sum[c][i] = 1 + sum[c][l[c]];
        for(int j=l[c];j<i;j++) {
            sum[c][j] = sum[c][l[c]];
        }
        l[c] = i;

        scanf("%c", &c);
        i++;
    }

    for(int j=0;j<27;j++) {
        for(int k=l[j]+1;k<i;k++) {
            sum[j][k] = sum[j][k-1];
        }
    }

    int q, a, b;
    scanf("%d", &q);
    for(int i=1;i<=q;i++)
    {
        scanf("%*c");
        scanf("%c %d %d", &c, &a, &b);
        c -= 'a';
        if(a == 0)
            printf("%d\n", sum[c][b]);
        else
            printf("%d\n", sum[c][b] - sum[c][a-1]);
    }

    return 0;
}