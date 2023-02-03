#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#define INF 1987654321

using namespace std;
char matrix[102][102];
int dist[102][102];
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int M, N;

void init()
{
    for(int i=0;i<102;i++) {
        for(int j=0;j<102;j++) {
            dist[i][j] = INF;
        }
    }
}

bool isIn(int y, int x)
{
    if(1<=x && x<=M && 1<=y && y<=N)
        return true;
    else
        return false;
}

void dijkstra()
{
    for(int l=1;l<=N;l++) {
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {1,1}});
        dist[1][1] = 0;

        while (!pq.empty()) {
            int cost = -pq.top().first;
            pair<int,int> cur = pq.top().second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                pair<int,int> next = {cur.first + direction[i][0], cur.second + direction[i][1]};
                if(!isIn(next.first,next.second)) continue;
                int nCost = cost + matrix[next.first][next.second] - '0';

                if (nCost < dist[next.first][next.second]) {
                    dist[next.first][next.second] = nCost;
                    pq.push({-nCost, next});
                }
            }
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    init();

    scanf("%d %d", &M, &N);
    for(int i=1;i<=N;i++) {
        scanf("%*c");
        for(int j=1;j<=M;j++) {
            scanf("%c", &matrix[i][j]);
        }
    }

    dijkstra();

    printf("%d", dist[N][M]);
    
    return 0;
}
