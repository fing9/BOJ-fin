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

    int T;
    cin >> T;

    while(T--)
    {
        int N, sx, sy, ex, ey, cnt = 0;
        cin >> sx >> sy >> ex >> ey;
        cin >> N;
        while(N--)
        {
            int a, b, d;
            cin >> a >> b >> d;
            if(sqrt(pow(abs(sx-a),2) + pow(abs(sy-b),2)) <= d || sqrt(pow(abs(ex-a),2) + pow(abs(ey-b),2)) <= d)
            {
                if(sqrt(pow(abs(sx-a),2) + pow(abs(sy-b),2)) > d || sqrt(pow(abs(ex-a),2) + pow(abs(ey-b),2)) > d)
                    cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
