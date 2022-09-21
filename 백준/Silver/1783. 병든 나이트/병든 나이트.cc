#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N, M, ret;
    cin >> N >> M;

    if(N == 1) {
        ret = 1;
    }
    else if(N == 2) {
        ret = min(4, (M+1)/2);
    }
    else if(M < 7) {
        ret = min(4, M);
    }
    else {
        ret = M - 2;
    }

    cout << ret;

    return 0;
}