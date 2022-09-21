#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned long long ret = 0;
    string  A, B;
    cin >> A >> B;
    
    for(int i=0;i<A.length();i++) {
        for(int j=0;j<B.length();j++) {
            ret += (A[i] - '0') * (B[j] - '0');
        }
    }
    
    cout << ret;
    
    return 0;
}