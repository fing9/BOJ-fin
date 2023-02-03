#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, last = 0;
    int ret[100000] = {0,};
    string A, B;
    cin >> N >> M;
    cin >> A;
    cin >> B;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            ret[i+j] += (A[N-i-1] - '0') * (B[M-j-1] - '0');
        }
    }

    for(int i=0;i<N+M;i++) {
        if(ret[i] >= 10) {
            ret[i+1] += ret[i] / 10;
            ret[i] %= 10;
            last = i+1;
        }
        else {
            if(ret[i] != 0)
                last = i;
        }
    }

    for(int i=last;i>=0;i--) {
        if(ret[i] == 0) {
            cout << 0;
        }
        else {
            cout << ret[i];
        }
    }

    return 0;
}