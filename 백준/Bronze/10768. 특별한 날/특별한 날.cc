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

    int M, D;
    scanf("%d", &M);
    scanf("%d", &D);

    if(M > 2 || M==2 && D > 18)
        cout << "After";
    else if(M < 2 || M==2 && D < 18)
        cout << "Before";
    else
        cout << "Special";

    return 0;
}