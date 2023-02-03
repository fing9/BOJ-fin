#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <bitset>
#define INF 987654321

using namespace std;

int N, M, K;
queue<pair<pair<int,pair<int,bool>>,pair<int,int>>> q;
int matrix[1002][1002];
int dist[1002][1002][11];
int di[4][2] = {{-1, 0},
                {0,  -1},
                {1,  0},
                {0,  1}};

void init() {
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            matrix[i][j] = 1;
            for(int l=0;l<11;l++)
                dist[i][j][l] = INF;
        }
    }
}

bool isIn(int y, int x) {
    if (1 <= y && y <= N && 1 <= x && x <= M) return true;
    else return false;
}

//true이낮
void bfs()
{
    //K cnt day Y X
    q.push({{0,{1,true}},{1,1}});
    for(int i=0;i<=K;i++)
        dist[1][1][i] = 1;

    while(!q.empty())
    {
        pair<int,int> cur = q.front().second;
        int nK = q.front().first.first;
        int cnt = q.front().first.second.first;
        bool day = q.front().first.second.second;
        q.pop();

        if(dist[cur.first][cur.second][nK] < cnt) continue;

        for(int i=0;i<4;i++)
        {
            pair<int,int> next = {cur.first + di[i][0], cur.second + di[i][1]};

            if(!isIn(next.first,next.second)) continue;

            if(matrix[next.first][next.second] == 0 && dist[next.first][next.second][nK] > cnt + 1)
            {
                dist[next.first][next.second][nK] = cnt + 1;
                //cheak[next.first][next.second] = 1;
                q.push({{nK, {cnt + 1, !day}},next});
            }

            if(matrix[next.first][next.second] == 1 && dist[next.first][next.second][nK + 1] > cnt + 1 && nK + 1 <= K && day == true)
            {
                dist[next.first][next.second][nK + 1] = cnt + 1;
                //cheak[next.first][next.second] = 1;
                q.push({{nK + 1, {cnt + 1, !day}},next});
            }

            if(matrix[next.first][next.second] == 1 && dist[next.first][next.second][nK + 1] > cnt + 2 && nK + 1 <= K && !day == true)
            {
                dist[next.first][next.second][nK + 1] = cnt + 2;
                //cheak[next.first][next.second] = 1;
                q.push({{nK + 1, {cnt + 2, day}},next});
            }

        }
    }

}



int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    char c;
    map<int, int> m;

    init();

    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%*c");
        for (int j = 1; j <= M; j++) {
            scanf("%c", &c);
            if (c == '1')
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }

    bfs();

    int ret = INF;
    for(int i=0;i<=K;i++){
        ret = min(ret, dist[N][M][i]);
    }

    if(ret == INF)
        printf("-1");
    else
        printf("%d", ret);

    return 0;
}