#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N, ret = 0;
    cin >> N;

    for(int i=1;i<=N;i++) {
        ret += pow(i,3);
    }

    cout << ret;

    return 0;
}