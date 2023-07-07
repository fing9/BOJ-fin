#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <unistd.h>

#define FAST ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define D_MAX 2147483647
#define LL_MAX 9223372036854775807
#define MAX 1000000001
#define MIN -1000000001
#define ll long long
#define ull unsigned long long
#define GRAPH vector<vector<pair<int, int>>>
#define CCW_MAX 100002

using namespace std;

// 1LL을 곱해주는 이유 = long long 자료형으로 형변환
// p랑 q가 뭘까나?
struct INFO {
    ll x, y;
    ll p, q;
    // x, y를 이용한 생성자
    INFO(ll x1 = 0, ll y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};

bool comp(const INFO &A, const INFO &B) {
    // 정렬 기준1) 만약 기준점을 기준으로 상대적인 위치가 계산된 뒤라면, 상대적인 위치를 기준으로 정렬
    if (A.q * B.p != A.p * B.q)
        return A.q * B.p < A.p * B.q;

    // 정렬 기준2) 아직 기준점을 기준으로 상대적 위치를 계산하지 않았다면, y와 x를 기준으로 오름차순 정렬
    if (A.y != B.y)
        return A.y < B.y;

    return A.x < B.x;
}

// first, second, next의 각을 계산해서 convex hull에 next가 포함되는지 여부를 
ll ccw(const INFO &A, const INFO &B, const INFO &C) {
    return ((A.x * B.y) + (B.x * C.y) + (C.x * A.y) - (B.x * A.y) - (C.x * B.y) - (A.x * C.y));
}

INFO p[CCW_MAX];

int main() {
    ll N;
    scanf("%lld", &N);

    for (ll i=0;i<N;i++) {
        ll x, y;
        
        scanf("%lld %lld", &x, &y);
        p[i] = INFO(x, y);
    }

    // y좌표, x좌표 순으로 오름차순 정렬
    sort(p, p + N, comp);

    // // 정렬 결과 테스트 #1
    // printf("sorted result #1\n");
    // for (int i=0;i<N;i++) {
    //     printf("x=%d y=%d\n", p[i].x, p[i].y);
    // }

    // 기준점으로부터 상대 위치 계산
    for (ll i=1;i<N;i++) {
        p[i].p = p[i].x - p[0].x;
        p[i].q = p[i].y - p[0].y;
    }

    // 반시계 반향으로 정렬(기준점 0을 제외)
    sort(p + 1, p + N, comp);
    
    // // 정렬 결과 테스트 #2
    // printf("sorted result #2\n");
    // for (int i=0;i<N;i++) {
    //     printf("x=%d y=%d\n", p[i].x, p[i].y);
    // }

    stack<ll> st;

    // 스택에 first, second를 넣어준다. <- 점의 개수가 최소 3개이기 때문
    // 기준점은 0번 점
    st.push(0);
    st.push(1);

    ll next = 2;
    while (next < N) {
        // 스택에 2개 이상의 점이 들어있다면
        while (st.size() >= 2) {
            ll first, second;
            // fisrt, second를 순서대로 꺼낸다.
            second = st.top();
            st.pop();
            first = st.top();

            // next와 ccw를 해서 (ccw값 > 0)(좌회전)인지 확인한다.
            //  -> 좌회전을 한다면 Convex hull이 될 수 있다
            //      -> pop했던 second를 다시 스택에 넣어주고 next를 스택에 넣어준다.(second를 Convex hull에 확정)
            //  -> 우회전을 한다면 Convex hull이 될 수 없다.
            //      -> pop했던 second를 넣지않고 다시 진행해본다. (second를 후보에서 제거)
            if (ccw(p[first], p[second], p[next]) > 0) {
                st.push(second);
                break;
            }
        }

        // next를 push
        st.push(next++);
    }

    // 스택에 들어간 점들이 Convex hull을 이루는 점들
    printf("%lu", st.size());

    return 0;
}
