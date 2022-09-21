#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;
int A, B, visited[10001];

void bfs(int s) {
    queue<pair<int,string>> q;
    q.push({s,""});
    visited[s] = 1;

    while(!q.empty()) {
        int p = q.front().first;
        string pV = q.front().second;
        q.pop();

        if(p == B) {
            cout << pV << "\n";
            return;
        }

        int dP = (p * 2) % 10000;
        if (visited[dP] == 0) { //D : p *= 2
            visited[dP] = 1;
            q.push({dP, pV + "D"});
        }

        int sP = p - 1 < 0 ? 9999 : p - 1;
        if (visited[sP] == 0) { //S : p -= 1
            visited[sP] = 1;
            q.push({sP, pV + "S"});
        }

        int lP = (p % 1000) * 10 + (p / 1000);
        if (visited[lP] == 0) { //L : 4321 -> 3214
            visited[lP] = 1;
            q.push({lP, pV + "L"});
        }

        int rP = (p % 10) * 1000 + (p / 10);
        if (visited[rP] == 0) { //R : 4321 -> 1432
            visited[rP] = 1;
            q.push({rP, pV + "R"});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        memset(visited, 0, sizeof(visited));
        cin >> A >> B;
        bfs(A);
    }

    return 0;
}