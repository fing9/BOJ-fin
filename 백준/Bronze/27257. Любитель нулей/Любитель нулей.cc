#include <iostream>
#include <string>

using namespace std;

int main() {
    string numStr;
   
    cin >> numStr;
    int cnt = 0;
    for (int i = 0; i < numStr.length(); i++) {
        if (numStr[i] == '0') {
            cnt++;
        }
    }

    for (int i = numStr.length() - 1; i != 0; i--) {
        if (numStr[i] == '0') {
            cnt--;
        }
        else {
            break ;
        }
    }
    cout << cnt;
    
    return 0;
}