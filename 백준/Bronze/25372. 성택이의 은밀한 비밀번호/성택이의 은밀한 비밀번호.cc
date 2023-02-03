#include <iostream>

using namespace std;

int main() {
    int N;
    
    cin >> N;
    while(N--) {
        string str;
        cin >> str;
        
        if(str.length() < 6 || 9 < str.length()) {
            cout << "no\n";
        }
        else {
            cout << "yes\n";
        }
    }
    
    return 0;
}