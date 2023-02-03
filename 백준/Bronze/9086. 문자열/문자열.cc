#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        string str;
        cin >> str;
        cout << str[0] << str[str.length()-1] << "\n";
    }

    return 0;
}