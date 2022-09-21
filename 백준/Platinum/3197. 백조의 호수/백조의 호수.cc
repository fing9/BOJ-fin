#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
char map[1600][1600];
int w_cheak[1600][1600], s_cheak[1600][1600];
int w_queue[2500000][2];
int w_nextqueue[2500000][2];
int s_queue[2500000][2];
int s_nextqueue[2500000][2];
int head=0, tail=0, nexthead=0, nexttail=0;
int s_head=0, s_tail=0, s_nexthead=0, s_nexttail=0;
int ry[4]={0, 0, 1, -1}, rx[4]={1, -1, 0, 0};
int swan_y=0, swan_x=0;

void bfs()
{
    int py, px;
    if(nexthead==nexttail)
    {
        while(head<tail)
        {
            py=w_queue[head][0];
            px=w_queue[head++][1];
            for(int i=0;i<4;i++)
            {
                if((map[py+ry[i]][px+rx[i]] == 'X') && (w_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    w_nextqueue[nexttail][0]=py+ry[i];
                    w_nextqueue[nexttail++][1]=px+rx[i];
                    w_cheak[py+ry[i]][px+rx[i]]=1;
                    map[py+ry[i]][px+rx[i]]='.';
                }
                else if(((map[py+ry[i]][px+rx[i]] == '.') || (map[py+ry[i]][px+rx[i]] == 'L')) && (w_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    w_queue[tail][0]=py+ry[i];
                    w_queue[tail++][1]=px+rx[i];
                    w_cheak[py+ry[i]][px+rx[i]]=1;
                }
            }
        }
    }
    else
    {
        while(nexthead<nexttail)
        {
            py=w_nextqueue[nexthead][0];
            px=w_nextqueue[nexthead++][1];
            for(int i=0;i<4;i++)
            {
                if((map[py+ry[i]][px+rx[i]] == 'X') && (w_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    w_queue[tail][0]=py+ry[i];
                    w_queue[tail++][1]=px+rx[i];
                    w_cheak[py+ry[i]][px+rx[i]]=1;
                    map[py+ry[i]][px+rx[i]]='.';
                }
                else if(((map[py+ry[i]][px+rx[i]] == '.') || (map[py+ry[i]][px+rx[i]] == 'L')) && (w_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    w_nextqueue[nexttail][0]=py+ry[i];
                    w_nextqueue[nexttail++][1]=px+rx[i];
                    w_cheak[py+ry[i]][px+rx[i]]=1;
                }
            }
        }
    } 
}

int swanbfs()
{
    int py, px;
    if(s_nexthead==s_nexttail)
    {
        while(s_head<s_tail)
        {
            py=s_queue[s_head][0];
            px=s_queue[s_head++][1];
            for(int i=0;i<4;i++)
            {
                if((map[py+ry[i]][px+rx[i]] == 'L') && ((py+ry[i] != swan_y) || (px+rx[i] != swan_x)))
                {
                    return 0;
                }
                if((map[py+ry[i]][px+rx[i]] == 'X') && (s_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    s_nextqueue[s_nexttail][0]=py+ry[i];
                    s_nextqueue[s_nexttail++][1]=px+rx[i];
                    s_cheak[py+ry[i]][px+rx[i]]=1;
                }
                else if((map[py+ry[i]][px+rx[i]] == '.') && (s_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    s_queue[s_tail][0]=py+ry[i];
                    s_queue[s_tail++][1]=px+rx[i];
                    s_cheak[py+ry[i]][px+rx[i]]=1;
                }
            }
        }
    }
    else
    {
        while(s_nexthead<s_nexttail)
        {
            py=s_nextqueue[s_nexthead][0];
            px=s_nextqueue[s_nexthead++][1];
            for(int i=0;i<4;i++)
            {
                if((map[py+ry[i]][px+rx[i]] == 'L') && ((py+ry[i] != swan_y) || (px+rx[i] != swan_x)))
                {
                    return 0;
                }
                else if((map[py+ry[i]][px+rx[i]] == 'X') && (s_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    s_queue[s_tail][0]=py+ry[i];
                    s_queue[s_tail++][1]=px+rx[i];
                    s_cheak[py+ry[i]][px+rx[i]]=1;
                }
                else if((map[py+ry[i]][px+rx[i]] == '.') && (s_cheak[py+ry[i]][px+rx[i]] == 0))
                {
                    s_nextqueue[s_nexttail][0]=py+ry[i];
                    s_nextqueue[s_nexttail++][1]=px+rx[i];
                    s_cheak[py+ry[i]][px+rx[i]]=1;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int R, C, x, y, d=0, found=0;
    char getc[1600];
    scanf("%d %d",&R,&C);
    
    for(int i=0;i<1600;i++) // 초기화 'W'는 벽
    {
        for(int j=0;j<1600;j++)
        {
            map[i][j] = 'W';
            w_cheak[i][j] = 0;
            s_cheak[i][j] = 0;
        }
    }
    
    for(int i=1;i<=R;i++)
    {
        scanf("%s",&getc);
        for(int j=0;j<C;j++)
        {
            map[i][j+1] = getc[j];
            if(map[i][j+1]=='L' && found==0)
            {
                y=i;
                x=j+1;
                s_queue[s_tail][0]=i;
                s_queue[s_tail++][1]=j+1;
                w_queue[tail][0]=i;
                w_queue[tail++][1]=j+1;
                w_cheak[i][j+1] = 1;
                s_cheak[i][j+1] = 1;
                swan_y=i;
                swan_x=j+1;
                found++;
            }
            else if(map[i][j+1]=='L' && found==1)
            {
                w_queue[tail][0]=i;
                w_queue[tail++][1]=j+1;
                w_cheak[i][j+1] = 1;
            }
            if(map[i][j+1]=='.')
            {
                w_queue[tail][0]=i;
                w_queue[tail++][1]=j+1;
                w_cheak[i][j+1] = 1;
            }
        }
    }
    
    while(swanbfs())
    {
        bfs();
        d++;
    }
    
    printf("%d",d);
    
    return 0;
}