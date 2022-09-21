#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    vector<char> v;
    char c;
    while(1)
    {
        scanf("%c", &c);
        v.push_back(c);

        if(c == '\n') {
            v.pop_back();
            while(!v.empty()) {
                cout << v.back();
                v.pop_back();
            }
            cout << "\n";
        }

        if(v.back() == 'D' && v.size() >= 3) {
            if(v[v.size()-2] == 'N') {
                if(v[v.size()-3] == 'E') {
                    break;
                }
            }
        }
    }

    return 0;
}