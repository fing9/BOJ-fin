#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <unistd.h>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define D_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 1000000001
#define MIN -1000000001
#define ll long long
#define ull unsigned long long
#define GRAPH vector<vector<pair<int, int>>>
#define CCW_MAX 100002
#define PII pair<ll,ll>
#define x first
#define y second
#define PI 3.14159265358979;

using namespace std;
int n1, n2, n3, n4;

int main() {
    FAST
    cin >> n1 >> n2 >> n3 >> n4;

    if ((n1 == 8 || n1 == 9) && (n2 == n3) && (n4 == 8 || n4 == 9)) cout << "ignore";
    else cout << "answer";

    return 0;
}