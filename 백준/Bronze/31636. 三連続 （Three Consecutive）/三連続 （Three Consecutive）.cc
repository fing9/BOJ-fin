#include <iostream>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;
    
    bool isInRow = true;
    int cur = 0, curMax = 0;
    for (int i=0;i<N;i++) {
        if (s[i] == 'o') {
            cur++;
            curMax = (cur < curMax ? curMax : cur);
        }
        else {
            cur = 0;
        }
    }
    if (curMax >= 3) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}