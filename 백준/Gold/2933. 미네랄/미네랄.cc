#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

using namespace std;

int R, C, N, inp, cntX = 0;
char matrix[102][102];

void gravity()
{
    int cheak[102][102];

    //cheak행렬 초기화
    for(int i=0;i<102;i++)
    {
        for(int j=0;j<102;j++)
            cheak[i][j] = 0;
    }

    //gravity() 실행전에 이미 던진 뒤임
    for(int i=R;i>=1;i--)
    {
        for(int j=1;j<=C;j++)
        {
            //cheak[i][j] == 0 AND matrix[i][j] == 'x' 일 때 dfs로 cheak를 다 1로 바꿔준다. 그 뒤 바꾼거의 갯수를 세서 cntX와 다르다면 떨어진 클러스터이므로 바닥과 연결될때까지 내린다.
            if(cheak[i][j] == 0 && matrix[i][j] == 'x')
            {
                bool isUnder = false;
                //dfs
                queue<pair<int,int>> q;
                int cnt = 0;
                q.push({i,j});
                cheak[i][j] = 1;
                while(!q.empty())
                {
                    cnt++;
                    pair<int,int> p;
                    p = q.front();
                    q.pop();

                    if(p.first == 1) isUnder = true;

                    if(cheak[p.first+1][p.second] == 0 && matrix[p.first+1][p.second] == 'x')
                    {
                        q.push({p.first+1,p.second});
                        cheak[p.first+1][p.second] = 1;
                    }
                    if(cheak[p.first-1][p.second] == 0 && matrix[p.first-1][p.second] == 'x')
                    {
                        q.push({p.first-1,p.second});
                        cheak[p.first-1][p.second] = 1;
                    }
                    if(cheak[p.first][p.second+1] == 0 && matrix[p.first][p.second+1] == 'x')
                    {
                        q.push({p.first,p.second+1});
                        cheak[p.first][p.second+1] = 1;
                    }
                    if(cheak[p.first][p.second-1] == 0 && matrix[p.first][p.second-1] == 'x')
                    {
                        q.push({p.first,p.second-1});
                        cheak[p.first][p.second-1] = 1;
                    }
                }

                //test
//                for(int q=1;q<=R;q++)
//                {
//                    for(int w=1;w<=C;w++)
//                    {
//                        printf("%d", matrix[q][w]);
//                    }
//                    printf("\n");
//                }

                if(cnt != cntX && isUnder == false) //떨어진 클러스터 발견
                {
                    bool isEnd = false;
                    while(!isEnd)
                    {
                        for (int k = 1; k <= R; k++)
                        {
                            for (int l = 1; l <= C; l++)
                            {
                                for (int m = 1; m <= C; m++)
                                {
                                    if(cheak[k][l] == 1 && cheak[k-1][l] != 1 && (matrix[k - 1][l] == 'x' || k-1 == 0))
                                    {
                                        isEnd = true;
                                        k = R+1;
                                        l = C+1;
                                    }
                                }
                            }
                        }

                        if(isEnd==true) break;

                        for (int k = 1; k <= R; k++)
                        {
                            for (int l = 1; l <= C; l++)
                            {
                                if (cheak[k][l] == 1 && matrix[k - 1][l] != 'x' && k-1!=0)
                                {
                                    cheak[k - 1][l] = 1;
                                    matrix[k - 1][l] = matrix[k][l];
                                    matrix[k][l] = '.';
                                }
                                else if(cheak[k][l] == 1 && (matrix[k - 1][l] == 'x' || k-1 == 0))
                                {
                                    isEnd = true;
                                    k = R+1;
                                    l = C+1;
                                }
                            }
                        }
                    }
                    return;
                }
                else if(cnt == cntX) //떨어진 클러스터 미발견
                {
                    return;
                }
                else //다른 클러스터 존재
                {
                    for (int k = 1; k <= R; k++)
                    {
                        for (int l = 1; l <= C; l++)
                        {
                            if (cheak[k][l] == 1)
                            {
                                cheak[k][l] = 2;
                            }
                        }
                    }
                }
            }
        }
    }
}


void throwStick(int h, int LR)
{
    if(LR == 0) //LEFT
    {
        for(int i=1;i<=C;i++)
        {
            if(matrix[h][i] == 'x')
            {
                cntX--;
                matrix[h][i] = '.';
                return;
            }
        }
    }
    else //RIGHT
    {
        for(int i=C;i>=1;i--)
        {
            if(matrix[h][i] == 'x')
            {
                cntX--;
                matrix[h][i] = '.';
                return;
            }
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    scanf("%d %d", &R, &C);

    for(int i=R;i>=1;i--)
    {
        scanf("%*c");
        for(int j=1;j<=C;j++)
        {
            scanf("%c", &matrix[i][j]);
            if(matrix[i][j] == 'x') cntX++;
        }
    }

    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%d", &inp);
        if(i%2 == 0)
        {
            throwStick(inp, 0);
        }
        else
        {
            throwStick(inp, 1);
        }
        gravity();
    }

    //put matrix
    for(int i=R;i>=1;i--)
    {
        for(int j=1;j<=C;j++)
        {
            printf("%c", matrix[i][j]);
        }
        if(i!=1)
            printf("\n");
    }


    return 0;
}
