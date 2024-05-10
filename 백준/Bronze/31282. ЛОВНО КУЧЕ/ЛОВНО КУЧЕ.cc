#include <iostream>

using namespace std;

int main() {
    long long N, M, K;
    cin >> N >> M >> K;
    cout << (long long)(((double)N / (double)(K - M)) + (N % (K - M) == 0 ? 0 : 1));
}