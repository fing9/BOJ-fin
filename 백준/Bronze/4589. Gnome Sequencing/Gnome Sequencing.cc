#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define INF 987654321

using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    cout << "Gnomes:" << "\n";

    int t;
    cin >> t;
    while(t--)
    {
        vector<int> v1, v2, v3;
        int a, b, c;
        cin >> a >> b >> c;

        v1.push_back(a);v1.push_back(b);v1.push_back(c);
        v2.push_back(a);v2.push_back(b);v2.push_back(c);
        v3.push_back(a);v3.push_back(b);v3.push_back(c);

        sort(v2.begin(),v2.end());
        sort(v3.begin(),v3.end(),greater<int>());

        if(v1 == v2 || v1 == v3)
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }

    return 0;
}