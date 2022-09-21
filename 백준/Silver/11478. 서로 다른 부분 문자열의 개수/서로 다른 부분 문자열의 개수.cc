#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    map<string, int> m;
    int cnt = 1;
    cin >> str;

    for(int i=0;i<str.length();i++)
    {
        for(int j=0;j<str.length();j++)
        {
            if (j + cnt <= str.length())
            {
                m.insert({str.substr(j, cnt), 1});
            }
        }
        cnt++;
    }

    cout << m.size();

    return 0;
}
