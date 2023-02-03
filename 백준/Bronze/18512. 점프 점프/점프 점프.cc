#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long x, y, p1, p2;
    cin >> x >> y >> p1 >> p2;

    if(p1 != p2 && x == y && x > abs(p1 - p2)) {
        cout << -1;
        return 0;
    }

    while(p1 != p2) {
        if(p1 > p2) p2 += y;
        else p1 += x;
        
        if(p1>1000000 || p2>1000000) {
            cout << -1;
            return 0;
        }
    }

    cout << p1;

    return 0;
}