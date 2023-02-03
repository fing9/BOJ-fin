#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int DP[1001]; // DP[지금 탐색중인 상자의 번호] = 지금 탐색중인 상자에 넣을 수 있는 최대 상자의 개수
    int n, inp, ret = 0;
    vector<int> v;

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &inp);
        v.push_back(inp);
        DP[i] = 0;
    }

    for(int i=0;i<n;i++) {
        DP[i] = 1; // 자기 자신은 무조건 담을 수 있으므로 최대 1은 보장
        for(int j=0;j<i;j++) { // 지금까지 담은 모든 최대 개수 값을 따져서 지금 상자의 최대 개수 값을 구한다.
            if(v[j] < v[i]) { // 지금 상자 안에 담을 수 있다면 
                DP[i] = max(DP[i], DP[j] + 1); // 담는게 더 많은지 이미 알고있는 최대 개수가 더 많은지 확인한다.
            }
        }
        ret = max(ret, DP[i]); // 전체 DP값 중 최대값이 답
    }

    printf("%d", ret);

    return 0;
}