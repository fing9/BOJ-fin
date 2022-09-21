#include <iostream>
using namespace std;
int N;
char map[10000][10000];

void draw(int y, int x, int level)
{
    if(level==3)
    {
        map[y][x]='*';
        map[y+1][x-1]='*';
        map[y+1][x+1]='*';
        map[y+2][x-2]='*';
        map[y+2][x-1]='*';
        map[y+2][x]='*';
        map[y+2][x+1]='*';
        map[y+2][x+2]='*';
        return;
    }
    else
    {
        draw(y,x,level/2);
        draw(y+(level/2),x-(level/2),level/2);
        draw(y+(level/2),x+(level/2),level/2);
    }
}

int main()
{
    cin >> N;
    
    draw(1,N,N);
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N*2;j++)
        {
            if(map[i][j]!='*')
                map[i][j] = ' ';
        }
    }
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N*2;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    
    return 0;
}