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
int dist[4][102][102];
int h, w;
int direction[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}}; //아래부터 반시계방향

void init()
{
    for(int i=0;i<102;i++) {
        for (int j = 0; j < 102; j++) {
            matrix[i][j] = '.';
        }
    }

    for(int l=0;l<3;l++) {
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                dist[l][i][j] = INF;
            }
        }
    }

    h = -1;
    w = -1;
}

bool isIn(int y, int x)
{
    if(0<=y && y<=h+1 && 0<=x && x<=w+1)
        return true;
    else
        return false;
}

int dijkstra(int y1, int x1, int y2, int x2)
{
    int start[3][2];
    start[0][0] = 0; start[0][1] = 0;
    start[1][0] = y1; start[1][1] = x1;
    start[2][0] = y2; start[2][1] = x2;

    for(int l=0;l<3;l++)
    {
        priority_queue<pair<int,pair<int,int>>> pq;

        dist[l][start[l][0]][start[l][1]] = 0;
        pq.push({0,{start[l][0],start[l][1]}});

        while(!pq.empty())
        {
            int cost = -pq.top().first;
            pair<int,int> cur = pq.top().second;
            pq.pop();

            for(int i=0;i<4;i++)
            {
                pair<int, int> next = {cur.first + direction[i][0], cur.second + direction[i][1]};
                //printf("l:%d  y:%d  x:%d \n", l, next.first, next.second);
                int newCost = cost;
                if(!isIn(next.first,next.second)) continue;
                if(matrix[next.first][next.second] == '*') continue;
                if(matrix[next.first][next.second] == '#') {
                    newCost += 1;
                }
                if(newCost < dist[l][next.first][next.second]) {
                    dist[l][next.first][next.second] = newCost;
                    pq.push({-newCost,next});
                }
            }
        }
    }

    int minD = INF;
    for(int i=1;i<=h;i++) {
        for (int j = 1; j <= w; j++) {
            dist[3][i][j] = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
            if(matrix[i][j] == '#')
                dist[3][i][j] -= 2;
            minD = min(dist[3][i][j], minD);
        }
    }

    return minD;
}

void printMatrix()
{
    for(int i = 0;i <= h+1; i++) {
        for (int j = 0; j <= w+1; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int T;
    scanf("%d", &T);

    while(T--)
    {
        int x1 = -1, y1 = -1, x2 = -1, y2 = -1; //(sx,sy) 처음으로 탐색을 시작할 $의 좌표
        int ret = -1;
        init();

        scanf("%d %d", &h, &w);
        for(int i=1;i<=h;i++)
        {
            scanf("%*c");
            for(int j=1;j<=w;j++)
            {
                scanf("%c", &matrix[i][j]);
                if(matrix[i][j] == '$' && x1 == -1 && y1 == -1)
                {
                    y1 = i;
                    x1 = j;
                }
                else if(matrix[i][j] == '$' && x1 != -1 && y1 != -1)
                {
                    y2 = i;
                    x2 = j;
                }
            }
        }

        ret = dijkstra(y1, x1, y2, x2);

        printf("%d\n", ret);
    }

    return 0;
}
