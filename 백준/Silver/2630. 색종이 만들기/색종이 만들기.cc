#include<iostream>
using namespace std;
int map[129][129], ans_w=0, ans_b=0;

void solve(int y, int x, int range)
{
    int color = map[y][x];
    int newrange = range/2;
    bool pure = true;
    
    for(int i=y;i<y+range;i++)
    {
        for(int j=x;j<x+range;j++)
        {
            if(color != map[i][j])
            {
                pure = false;
                i = y+range+1;
                j = x+range+1;
            }
        }
    }
    
    if(pure)
    {
        if(color==0) ans_w++;
        else ans_b++;
    }
    else
    {
        solve(y, x, newrange);
        solve(y, x + newrange, newrange);
        solve(y + newrange, x, newrange);
        solve(y + newrange, x + newrange, newrange);
    }
}

int main()
{
    int N;
    //입력부
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }

    //처리부
    solve(0, 0, N);
    
    printf("%d\n%d", ans_w, ans_b);
    
    return 0;
}