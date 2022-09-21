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

    int K, N, M;
    cin >> K >> N >> M;

    if((K*N) <= M)
        cout << "0";
    else
        cout << (K*N) - M;

    return 0;
}