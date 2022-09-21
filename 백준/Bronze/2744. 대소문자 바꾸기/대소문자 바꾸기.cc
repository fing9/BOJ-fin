#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    for(int i=0;i<str.length();i++)
    {
        if('a'<=str[i] && str[i]<='z')
            str[i] = 'A' + str[i] - 'a';
        else
            str[i] = 'a' + str[i] - 'A';
    }

    cout << str;

    return 0;
}
