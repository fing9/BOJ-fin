#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int L, A, B, C, D;
    int ret1, ret2;

    cin >> L;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    ret1 = A/C;
    ret2 = B/D;
    if(A%C != 0) ret1++;
    if(B%D != 0) ret2++;

    cout << min(L-ret1, L-ret2);

    return 0;
}