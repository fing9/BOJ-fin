#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
#define NO_ANSWER "Madness"
#define ZERO "ZERO"
#define ONE "ONE"
#define TWO "TWO"
#define THREE "THREE"
#define FOUR "FOUR"
#define FIVE "FIVE"
#define SIX "SIX"
#define SEVEN "SEVEN"
#define EIGHT "EIGHT"
#define NINE "NINE"


using namespace std;
string eq;
string nbr_eq;
string ans_str;
vector<int> indexes;
ll ans = 0;

ll strtolonglong(string str, int sIdx, int eIdx) {
    ll nbr = 0;
    while (sIdx < eIdx) {
        nbr *= 10;
        nbr += str[sIdx++] - '0';
    }
    return nbr;
}

int strlen(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void print() {
    for (int i=0;i<ans_str.length();i++) {
        if (ans_str[i] == '0') {
            cout << ZERO;
        } else if (ans_str[i] == '1') {
            cout << ONE;
        } else if (ans_str[i] == '2') {
            cout << TWO;
        } else if (ans_str[i] == '3') {
            cout << THREE;
        } else if (ans_str[i] == '4') {
            cout << FOUR;
        } else if (ans_str[i] == '5') {
            cout << FIVE;
        } else if (ans_str[i] == '6') {
            cout << SIX;
        } else if (ans_str[i] == '7') {
            cout << SEVEN;
        } else if (ans_str[i] == '8') {
            cout << EIGHT;
        } else if (ans_str[i] == '9') {
            cout << NINE;
        }
    }
}

int main() {
    cin >> eq;
    bool valid = true;
    for (int i=0;i<eq.length();i++) {
        bool isSomething = false;
        if (i + strlen(ZERO) < eq.length()) {
            if (!eq.substr(i,strlen(ZERO)).compare(ZERO)) {
                nbr_eq.push_back('0');
                isSomething = true;
                i += 3;
                continue;
            }
        }
        if (i + strlen(ONE) < eq.length()) {
            if (!eq.substr(i,strlen(ONE)).compare(ONE)) {
                nbr_eq.push_back('1');
                isSomething = true;
                i += 2;
                continue;
            }
        }
        if (i + strlen(TWO) < eq.length()) {
            if (!eq.substr(i,strlen(TWO)).compare(TWO)) {
                nbr_eq.push_back('2');
                isSomething = true;
                i += 2;
                continue;
            }
        }
        if (i + strlen(THREE) < eq.length()) {
            if (!eq.substr(i,strlen(THREE)).compare(THREE)) {
                nbr_eq.push_back('3');
                isSomething = true;
                i += 4;
                continue;
            }
        }
        if (i + strlen(FOUR) < eq.length()) {
            if (!eq.substr(i,strlen(FOUR)).compare(FOUR)) {
                nbr_eq.push_back('4');
                isSomething = true;
                i += 3;
                continue;
            }
        }
        if (i + strlen(FIVE) < eq.length()) {
            if (!eq.substr(i,strlen(FIVE)).compare(FIVE)) {
                nbr_eq.push_back('5');
                isSomething = true;
                i += 3;
                continue;
            }
        }
        if (i + strlen(SIX) < eq.length()) {
            if (!eq.substr(i,strlen(SIX)).compare(SIX)) {
                nbr_eq.push_back('6');
                isSomething = true;
                i += 2;
                continue;
            }
        }
        if (i + strlen(SEVEN) < eq.length()) {
            if (!eq.substr(i,strlen(SEVEN)).compare(SEVEN)) {
                nbr_eq.push_back('7');
                isSomething = true;
                i += 4;
                continue;
            }
        }
        if (i + strlen(EIGHT) < eq.length()) {
            if (!eq.substr(i,strlen(EIGHT)).compare(EIGHT)) {
                nbr_eq.push_back('8');
                isSomething = true;
                i += 4;
                continue;
            }
        }
        if (i + strlen(NINE) < eq.length()) {
            if (!eq.substr(i,strlen(NINE)).compare(NINE)) {
                nbr_eq.push_back('9');
                isSomething = true;
                i += 3;
                continue;
            }
        }
        if (eq[i] == '+' || eq[i] == '-' || eq[i] == '/' || eq[i] == 'x' || eq[i] == '=') {
            nbr_eq.push_back(eq[i]);
            indexes.push_back(nbr_eq.size() - 1);
            isSomething = true;
        }
        if (!isSomething) {
            valid = false;
            break;
        }
    }
    if (!valid) {
        cout << "Madness!";
        return 0;
    }

    for (int i=0;i<indexes.size();i++) {
        if (i == 0) {
            if (indexes[i] == 0) {
                valid = false;
                break;
            }
            ans = strtolonglong(nbr_eq, 0, indexes[i]);
            if (ans == 0) {
                valid = false;
                break;
            }
        } else {
            if (indexes[i - 1] + 1 == indexes[i]) {
                valid = false;
                break;
            }
            if (nbr_eq[indexes[i - 1]] == '-') {
                ans -= strtolonglong(nbr_eq, indexes[i - 1] + 1, indexes[i]);
            } else if (nbr_eq[indexes[i - 1]] == '+') {
                ans += strtolonglong(nbr_eq, indexes[i - 1] + 1, indexes[i]);
            } else if (nbr_eq[indexes[i - 1]] == 'x') {
                ans *= strtolonglong(nbr_eq, indexes[i - 1] + 1, indexes[i]);
            } else if (nbr_eq[indexes[i - 1]] == '/') {
                ans /= strtolonglong(nbr_eq, indexes[i - 1] + 1, indexes[i]);
            } else if (nbr_eq[indexes[i - 1]] == '=') {
                valid = false;
                break;
            }
        }
    }
    if (!valid || nbr_eq[nbr_eq.size() - 1] != '=' || nbr_eq.size() <= 1) {
        cout << "Madness!";
        return 0;
    }
    cout << nbr_eq << "\n";
    if (ans < 0) {
        cout << "-";
        ans *= -1;
    }
    ans_str = to_string(ans);
    print();

    return 0;
}
