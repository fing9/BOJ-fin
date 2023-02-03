#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <utility>

#define INF 987654321

using namespace std;

int main() {
    string myMbti, curMbti;
    int N, cnt = 0;

    cin >> myMbti;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> curMbti;
        if(!myMbti.compare(curMbti)) cnt++;
    }

    cout << cnt;

    return 0;
}