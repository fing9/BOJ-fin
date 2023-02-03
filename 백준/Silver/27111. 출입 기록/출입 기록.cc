#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, int> um;
    int N;
    int a, cmd, cnt = 0;

    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &a, &cmd);
        if(cmd == 1) {
            if(um.find(a) != um.end()) {
                cnt++;
            }
            else {
                um.insert({a, a});
            }
        }
        else {
            if(um.find(a) != um.end()) {
                um.erase(a);
            }
            else {
                cnt++;
            }
        }
    }

    cnt += um.size();

    printf("%d", cnt);

    return 0;
}