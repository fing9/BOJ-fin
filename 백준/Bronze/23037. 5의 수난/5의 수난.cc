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

    unsigned long long N, sum = 0;
    cin >> N;

    while(N > 0)
    {
        sum += pow(N % 10,5);
        N /= 10;
    }

    cout << sum;

    return 0;
}