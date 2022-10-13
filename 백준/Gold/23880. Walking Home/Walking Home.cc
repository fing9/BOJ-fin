#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

bool isNotBlocked(char matrix[][52], int x, int y, int N);
int bfs(char matrix[][52], int N, int K);

bool isNotBlocked(char matrix[][52], int x, int y, int N) {
    if((0 < x && x <= N) && (0 < y && y <= N) && matrix[x][y] != 'H') return true;
    else return false;
}

int bfs(char matrix[][52], int N, int K) {
    int ret = 0;
    queue<pair<pair<int, int>, pair<int, int>>> q; // queue <<cnt, last>, <x, y>>    last : 1은 오른쪽 0은 아래방향 2는 예외
    q.push({{0,2},{1,1}});

    while(!q.empty()) {
        int cnt = q.front().first.first;
        int mode = q.front().first.second;
        pair<int,int> cur = q.front().second;
        q.pop();

        if(cur.first == N && cur.second == N) {
            ret++;
            continue;
        }

        if(isNotBlocked(matrix, cur.first+1, cur.second, N)) {
            if(mode == 1 || mode == 2) {
                q.push({{cnt, 1}, {cur.first+1, cur.second}});
            }
            else if(cnt+1 <= K){
                q.push({{cnt+1, 1}, {cur.first+1, cur.second}});
            }
        }

        if(isNotBlocked(matrix, cur.first, cur.second+1, N)) {
            if(mode == 0 || mode == 2) {
                q.push({{cnt, 0}, {cur.first, cur.second+1}});
            }
            else if(cnt+1 <= K){
                q.push({{cnt+1, 0}, {cur.first, cur.second+1}});
            }
        }
    }

    return ret;
}

int main() {
    int T;

    scanf("%d", &T);
    while(T--) {
        char matrix[52][52];
        int N, K;
        scanf("%d %d", &N, &K);

        for(int i=0;i<52;i++) {
            for(int j=0;j<52;j++) {
                matrix[i][j] = 'H';
            }
        }

        for(int i=1;i<=N;i++) {
            getchar();
            for(int j=1;j<=N;j++) {
                scanf("%c", &matrix[i][j]);
            }
        }

        printf("%d\n", bfs(matrix, N, K));

    }

    return 0;
}