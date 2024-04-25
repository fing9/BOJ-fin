#include<iostream>

using namespace std;

int main() {
    int X, L, R;
    
    cin >> X >> L >> R;
    if (L <= X && X <= R) {
        cout << X;
    } else if (X < L) {
        cout << L;
    } else {
        cout << R;
    }
}