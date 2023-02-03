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

    int a, b, x, y;
    cin >> a >> b;

    x = (a + b) / 2;
    y = (a - b) / 2;

    if(a < b) {
        cout << "-1";
        return 0;
    }

    if(x+y==a && x-y==b)
        cout << x << " " << y;
    else
        cout << "-1";

    return 0;
}