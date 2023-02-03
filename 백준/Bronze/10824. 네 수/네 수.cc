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
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    unsigned long long AB = 0, CD = 0;
    string strA, strB, strC, strD;
    cin >> strA >> strB >> strC >> strD;

    strA += strB;
    strC += strD;

    for(int i=0;i<strA.length();i++)
    {
        AB *= 10;
        AB += strA[i] - '0';
    }

    for(int i=0;i<strC.length();i++)
    {
        CD *= 10;
        CD += strC[i] - '0';
    }

    cout << AB+CD;

    return 0;
}
