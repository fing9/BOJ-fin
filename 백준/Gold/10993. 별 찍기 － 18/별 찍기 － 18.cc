#include <iostream>
using namespace std;
char map[10050][10050];
int N;

void draw(int y, int x, int m, int level)
{
    int sps=0;
    if(level==1)
    {
        map[y][x]='*';
        return;
    }
    else
    {
        if(level%2==0) // 짝수일 때
        {
            for(int i=0;i<(m*2)-1;i++)
                map[y][x+i]='*';
            for(int i=0;i<m;i++)
            {
                map[y+i][x+i]='*';
                map[y+i][x+(m*2)-2-i]='*';
                sps++;
            }
            draw(y-1+(m+1)/2,x+((m+1)/2),((m+1)/2)-1,level-1);
        }
        else // 홀수일 때
        {
            for(int i=0;i<(m*2)-1;i++)
                map[y][x+i]='*';
            for(int i=0;i<m;i++)
            {
                map[y-i][x+i]='*';
                map[y-i][x+(m*2)-2-i]='*';
                sps++;
            }
            draw(y-((m+1)/2)+1,x+((m+1)/2),((m+1)/2)-1,level-1);
        }
    }
}

int main()
{
    int left=2;
    cin >> N;
    
    for(int i=1;i<N;i++)
        left*=2;
    left--;
    
    if(N==1)
    {
        printf("*");
        return 0;
    }
    else
    {
        if(N%2==0) // N이 짝수이면
        {
            draw(1,1,left,N);
        }
        else // N이 홀수이면
        {
            draw(left,1,left,N);
        }
    }
    
    for(int i=1;i<=(left*2)-1;i++)
    {
        for(int j=1;j<=(left*2)-1;j++)
        {
            if(map[i][j]!='*')
                map[i][j]=' ';
        }
    }
    
    int k=1;
    
    if(N%2==0)
    {
        for(int i=1;i<=left;i++)
        {
            for(int j=1;j<=(left*2)-k;j++)
            {
                cout << map[i][j];
            }
            k++;
            if(i!=left)
                cout << endl;
        }
    }
    else
    {
        for(int i=1;i<=left;i++)
        {
            for(int j=1;j<=left+k-1;j++)
            {
                cout << map[i][j];
            }
            k++;
            if(i!=left)
                cout << endl;
        }
    }
    // 감상평 : 너무 주먹구구로 더럽게 푼 듯 하다.
    return 0;
}