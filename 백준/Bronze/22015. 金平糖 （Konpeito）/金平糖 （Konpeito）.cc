#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= b&& a >= c) {
        cout << (2 * a) - (b + c);
    } else if (b >= a&& b >= c) {
        cout << (2 * b) - (a + c);
    } else {
        cout << (2 * c) - (a + b);
    }
}