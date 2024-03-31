#include <iostream>
#include <string>

using namespace std;

string numbers[10] = {"0000\n0  0\n0  0\n0  0\n0000",
                      "   1\n   1\n   1\n   1\n   1",
                      "2222\n   2\n2222\n2\n2222",
                      "3333\n   3\n3333\n   3\n3333",
                      "4  4\n4  4\n4444\n   4\n   4",
                      "5555\n5\n5555\n   5\n5555",
                      "6666\n6\n6666\n6  6\n6666",
                      "7777\n   7\n   7\n   7\n   7",
                      "8888\n8  8\n8888\n8  8\n8888",
                      "9999\n9  9\n9999\n   9\n   9"
};

int main() {
    string nbr;

    cin >> nbr;
    for (int i=0;i<nbr.size();i++) {
        cout << numbers[nbr[i] - '0'];
        if (i + 1 != nbr.size())
            cout << "\n\n";
    }

    return 0;
}
