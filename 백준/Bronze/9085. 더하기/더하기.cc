#include <iostream>

using namespace std;

int main() {
    int t;
    
    cin >> t;
    
    while(t--) {
        int n, sum = 0;
        
        cin >> n;
        for(int i=0;i<n;i++) {
            int inp;
            cin >> inp;
            sum += inp;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}