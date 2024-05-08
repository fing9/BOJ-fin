#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        string str;
        int cnt;
        double sum = 0, cur;
        for (int i=0;i<N;i++) {
            cin >> str >> cnt >> cur;
            sum += cnt * cur;
        }
        cout << fixed;
        cout.precision(2);
        cout << "$" << sum << "\n";
    }
}