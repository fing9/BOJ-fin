#include <iostream>

using namespace std;

int main() {
    int T, F, S, P, C, ret;
    
    for(int i=0;i<2;i++) {
        cin >> T >> F >> S >> P >> C;
        
        ret = (6 * T) + (3 * F) + (2 * S) + (1 * P) + (2 * C);
        
        cout << ret << " ";
    }
    
    return 0;
}