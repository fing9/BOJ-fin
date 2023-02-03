#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;

    cin >> a;
    cin >> b;

    if(a.length()>=b.length())
        cout << "go";
    else
        cout << "no";

    return 0;
}
