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

    vector<int> v;
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    sort(v.begin(),v.end());

    printf("%d %d %d", v[0], v[1], v[2]);

    return 0;
}