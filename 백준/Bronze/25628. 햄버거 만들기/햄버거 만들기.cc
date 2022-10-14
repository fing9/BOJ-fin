#include <iostream>

using namespace std;

int main() {
    int A, B, ret = 0;
    cin >> A >> B;
    
    while(A>=2 && B>=1) {
        ret++;
        A-=2;
        B-=1;
    }
    
    cout << ret;
    
    return 0;
}