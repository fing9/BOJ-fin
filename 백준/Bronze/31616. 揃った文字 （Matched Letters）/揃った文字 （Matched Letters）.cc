#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    string str;
    cin >> N;
    cin >> str;
    for (int i=1;i<str.size();i++) {
        if (str[0] != str[i]) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}