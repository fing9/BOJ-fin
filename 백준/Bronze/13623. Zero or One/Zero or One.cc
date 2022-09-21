#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    if(A+B+C == 3 || A+B+C == 0) {
        cout << "*";
        return 0;
    }
    if(B==C) cout << "A";
    else if(A==C) cout << "B";
    else cout << "C";
    
    return 0;
}