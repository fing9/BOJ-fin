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

    int a=0, b=0, n;

    for(int i=0;i<4;i++) {
        cin >> n;
        a += n;
    }

    for(int i=0;i<4;i++) {
        cin >> n;
        b += n;
    }

    if(a>b)
        cout << a;
    else
        cout << b;

    return 0;
}