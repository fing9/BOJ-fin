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

    vector<int> v;
    int a, b, c, sum;

    cin >> a;
    cin >> b;
    cin >> c;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    sum = v[0] + v[1] + v[2];

    sort(v.begin(),v.end());

    if(v[0]==60 && v[1]==60 && v[2]==60) {
        cout << "Equilateral";
    }
    else if((sum == 180) && (v[0]==v[1] || v[1]==v[2] || v[0]==v[2])) {
        cout << "Isosceles";
    }
    else if(sum == 180) {
        cout << "Scalene";
    }
    else {
        cout << "Error";
    }

    return 0;
}