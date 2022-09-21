#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int W, H, X, Y, P, a, b, cnt = 0;
    double px1, py1, px2, py2, d;

    cin >> W >> H >> X >> Y >> P;

    d = H / 2;
    px1 = X;
    py1 = Y + d;
    px2 = X + W;
    py2 = Y + d;

    while(P--)
    {
        cin >> a >> b;
        if((sqrt(pow(abs(px1 - a),2) + pow(abs(py1 - b),2)) <= d) || (sqrt(pow(abs(px2 - a),2) + pow(abs(py2 - b),2)) <= d) || (X<=a && Y<=b && a<=X+W && b<=Y+H))
            cnt++;
    }

    cout << cnt;

    return 0;
}
