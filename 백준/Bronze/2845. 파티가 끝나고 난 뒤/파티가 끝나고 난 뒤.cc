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

    int L, P;
    int part[5];

    cin >> L >> P;
    cin >> part[0] >> part[1] >> part[2] >> part[3] >> part[4];

    cout << part[0] - (L * P) << " " << part[1] - (L * P) << " " << part[2] - (L * P) << " " << part[3] - (L * P) << " "
         << part[4] - (L * P);

    return 0;
}