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
    map<string, int> m;
    int N, M, cnt = 0;

    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        string str;
        cin >> str;
        m.insert({str,1});
    }

    for(int i=0;i<M;i++)
    {
        string str;
        cin >> str;
        if(m.find(str) != m.end()) cnt++;
    }

    cout << cnt;

    return 0;
}
