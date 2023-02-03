#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v6, v1;
    int N, M, ret = 0;
    cin >> N >> M;

    for(int i=0;i<M;i++) {
        int x6, x1;
        cin >> x6 >> x1;
        v6.push_back(x6);
        v1.push_back(x1);
    }

    sort(v1.begin(), v1.end());
    sort(v6.begin(), v6.end());

    if(v6[0] < (v1[0] * 6)) {
        ret += (N / 6) * v6[0];
        N %= 6;
    }
    else {
        ret += N * v1[0];
        N = 0;
    }

    if(N>0 && (v6[0] < v1[0] * N)) {
        ret += v6[0];
        N = 0;
    }
    else{
        ret += N * v1[0];
        N = 0;
    }


    cout << ret;

    return 0;
}