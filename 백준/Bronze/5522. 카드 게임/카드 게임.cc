#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[5], sum = 0;
    for(int i=0;i<5;i++) {
        cin >> A[i];
        sum += A[i];
    }

    cout << sum;

    return 0;
}
