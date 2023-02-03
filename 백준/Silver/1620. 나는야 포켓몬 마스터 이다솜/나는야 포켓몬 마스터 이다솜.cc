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
    map<string, int> m;
    string arr[100001];
    int N, M, cnt = 0;

    cin >> N >> M;

    for(int i=1;i<=N;i++)
    {
        string str;
        cin >> str;
        m.insert({str,i});
        arr[i] = str;
    }

    for(int i=0;i<M;i++)
    {
        string str;
        int num;
        cin >> str;
        if('0' <= str.at(0) && str.at(0) <= '9')
        {
            num = stoi(str);
            cout << arr[num] << "\n";
        }
        else
        {
            cout << m.find(str)->second << "\n";
        }
    }

    return 0;
}
