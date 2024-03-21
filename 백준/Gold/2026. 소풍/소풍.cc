#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int K, N, F;
int counts[901];
bool isFriend[901][901];
bool visited[901];
vector<vector<int>> graph(901);

bool isPossible(int nbr, vector<int> team) {
    for (int i=0;i<team.size();i++) {
        if (nbr == team[i])
            continue;
        if (!isFriend[nbr][team[i]]) {
            return false;
        }
    }
    return true;
}

bool solve(int curK, vector<int> team) {
    if (curK == K) {
        sort(team.begin(), team.end());
        for (int i=0;i<K;i++) {
            printf("%d\n", team[i]);
        }
        return true;
    }
    for (int i=1;i<=N;i++) {
        if (visited[i] || counts[i] < K - 1) {
            continue;
        }
        bool pos = true;
        team.push_back(i);
        for (int j=0;j<curK;j++) {
            if (!isPossible(team[j], team)) {
                pos = false;
                break;
            }
        }
        if (pos) {
            pos = isPossible(i, team);
        }
        if (pos) {
            visited[i] = true;
            if (solve(curK + 1, team))
                return true;
            visited[i] = false;
        }
        team.pop_back();
    }
    return false;
}

int main() {
    scanf("%d %d %d", &K, &N, &F);

    for (int i=0;i<F;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        isFriend[a][b] = true;
        isFriend[b][a] = true;
        counts[a]++;
        counts[b]++;
    }
    if (!solve(0, vector<int>()))
        printf("-1");

    return 0;
}