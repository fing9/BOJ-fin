#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int c = 0, b = 0;
    for (int i=0;i<str.size();i++) {
        if (str[i] == 'C')
            c++;
        else
            b++;
    }
    printf("%d", (c / 2) + (b / 2));
}