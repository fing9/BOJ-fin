#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>
#include <set>
#define INF 1987654321

using namespace std;

int tree[4000001];
int n, a, b, c;

void edit(int index, int left, int right, int target, int diff) {
    if(target < left || right < target) return;

    tree[index] += diff;
    if(left == right) return;

    int mid = (left + right) / 2;
    edit(index*2, left, mid, target, diff);
    edit(index*2 + 1, mid+1, right, target, diff);
}

int pickup(int index, int left, int right, int target) {
    if(left == right) return left;

    int mid = (left + right) / 2;
    if (target <= tree[index*2]) {
        return pickup(index*2, left, mid, target);
    }
    else{
        return pickup(index*2+1, mid + 1, right, target - tree[index*2]);
    }
}

int main()
{
    int ret, rank;
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d", &a);
        if(a==1) {
            // b번째 순위의 사탕을 한 개 꺼낸다.
            scanf("%d", &b);
            ret = pickup(1, 1, 1000000, b);
            edit(1, 1, 1000000, ret, -1);
            printf("%d\n", ret);
        }
        else {
            // 맛이 b인 사탕을 c개 주머니에 넣는다.
            scanf("%d %d", &b, &c);
            edit(1, 1, 1000000, b, c);
        }
    }

    return 0;
}