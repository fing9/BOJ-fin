#include<iostream>

using namespace std;

int main() {
    int Z;
    
    cin >> Z;
    while(Z--) {
        int W, K;
        cin >> W >> K;
        cout << (W * K) / 2 << "\n";
    }
    
    return 0;
}