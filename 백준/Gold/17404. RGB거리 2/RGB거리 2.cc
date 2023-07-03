#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <unistd.h>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INT_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 1000000001
#define MIN -1000000001
#define ll long long
#define ull unsigned long long
#define GRAPH vector<vector<pair<int, int>>>

using namespace std;

int N;
pair<int,int> DP[1001][3];
pair<int,int> DP2[1001][3];
pair<int,int> DP3[1001][3];
int rgb[1001][3];

int main() {

    scanf("%d", &N);
    for (int i=1;i<=N;i++) {
        int r, g, b;

        scanf("%d %d %d", &r, &g, &b);
        rgb[i][0] = r;
        rgb[i][1] = g;
        rgb[i][2] = b;
        DP[i][0].first = MAX;
        DP[i][1].first = MAX;
        DP[i][2].first = MAX;
        DP[i][0].second = 3;
        DP[i][1].second = 3;
        DP[i][2].second = 3;
        DP2[i][0].first = MAX;
        DP2[i][1].first = MAX;
        DP2[i][2].first = MAX;
        DP2[i][0].second = 3;
        DP2[i][1].second = 3;
        DP2[i][2].second = 3;
        DP3[i][0].first = MAX;
        DP3[i][1].first = MAX;
        DP3[i][2].first = MAX;
        DP3[i][0].second = 3;
        DP3[i][1].second = 3;
        DP3[i][2].second = 3;
    }

    DP[N][1].first = rgb[N][1];
    DP[N][1].second = 1;
    DP[N][2].first = rgb[N][2];
    DP[N][2].second = 2;
    for (int i=N-1;i>0;i--) {
        if (DP[i + 1][1].first < DP[i + 1][2].first) {
            DP[i][0].first = rgb[i][0] + DP[i + 1][1].first;
            DP[i][0].second = DP[i+1][1].second;
        }
        else {
            DP[i][0].first = rgb[i][0] + DP[i + 1][2].first;
            DP[i][0].second = DP[i+1][2].second;
        }
        if (DP[i + 1][0].first < DP[i + 1][2].first) {
            DP[i][1].first = rgb[i][1] + DP[i + 1][0].first;
            DP[i][1].second = DP[i+1][0].second;
        }
        else {
            DP[i][1].first = rgb[i][1] + DP[i + 1][2].first;
            DP[i][1].second = DP[i+1][2].second;
        }
        if (DP[i + 1][0].first < DP[i + 1][1].first) {
            DP[i][2].first = rgb[i][2] + DP[i + 1][0].first;
            DP[i][2].second = DP[i+1][0].second;
        }
        else {
            DP[i][2].first = rgb[i][2] + DP[i + 1][1].first;
            DP[i][2].second = DP[i+1][1].second;
        }
    }
    DP2[N][0].first = rgb[N][0];
    DP2[N][0].second = 0;
    DP2[N][2].first = rgb[N][2];
    DP2[N][2].second = 2;
    for (int i=N-1;i>0;i--) {
        if (DP2[i + 1][1].first < DP2[i + 1][2].first) {
            DP2[i][0].first = rgb[i][0] + DP2[i + 1][1].first;
            DP2[i][0].second = DP2[i+1][1].second;
        }
        else {
            DP2[i][0].first = rgb[i][0] + DP2[i + 1][2].first;
            DP2[i][0].second = DP2[i+1][2].second;
        }
        if (DP2[i + 1][0].first < DP2[i + 1][2].first) {
            DP2[i][1].first = rgb[i][1] + DP2[i + 1][0].first;
            DP2[i][1].second = DP2[i+1][0].second;
        }
        else {
            DP2[i][1].first = rgb[i][1] + DP2[i + 1][2].first;
            DP2[i][1].second = DP2[i+1][2].second;
        }
        if (DP2[i + 1][0].first < DP2[i + 1][1].first) {
            DP2[i][2].first = rgb[i][2] + DP2[i + 1][0].first;
            DP2[i][2].second = DP2[i+1][0].second;
        }
        else {
            DP2[i][2].first = rgb[i][2] + DP2[i + 1][1].first;
            DP2[i][2].second = DP2[i+1][1].second;
        }
    }

    DP3[N][0].first = rgb[N][0];
    DP3[N][0].second = 0;
    DP3[N][1].first = rgb[N][1];
    DP3[N][1].second = 1;
    for (int i=N-1;i>0;i--) {
        if (DP3[i + 1][1].first < DP3[i + 1][2].first) {
            DP3[i][0].first = rgb[i][0] + DP3[i + 1][1].first;
            DP3[i][0].second = DP3[i+1][1].second;
        }
        else {
            DP3[i][0].first = rgb[i][0] + DP3[i + 1][2].first;
            DP3[i][0].second = DP3[i+1][2].second;
        }
        if (DP3[i + 1][0].first < DP3[i + 1][2].first) {
            DP3[i][1].first = rgb[i][1] + DP3[i + 1][0].first;
            DP3[i][1].second = DP3[i+1][0].second;
        }
        else {
            DP3[i][1].first = rgb[i][1] + DP3[i + 1][2].first;
            DP3[i][1].second = DP3[i+1][2].second;
        }
        if (DP3[i + 1][0].first < DP3[i + 1][1].first) {
            DP3[i][2].first = rgb[i][2] + DP3[i + 1][0].first;
            DP3[i][2].second = DP3[i+1][0].second;
        }
        else {
            DP3[i][2].first = rgb[i][2] + DP3[i + 1][1].first;
            DP3[i][2].second = DP3[i+1][1].second;
        }
    }

    printf("%d", min(DP[1][0].first, min(DP2[1][1].first, DP3[1][2].first)));

    return (0);
}
