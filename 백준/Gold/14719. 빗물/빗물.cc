#include <iostream>
using namespace std;
int map[502][502], H, W, ret = 0;
int nowsum=0;
bool closed = false;

int main()
{
    for(int i=0;i<502;i++)
    {
        for(int j=0;j<502;j++)
        {
            map[i][j] = -1;
        }
    }
    
    scanf("%d %d",&H,&W);
    for(int i=0;i<W;i++)
    {
        int now;
        scanf("%d", &now);
        for(int j=0;j<now;j++)
        {
            map[j][i] = 1;
        }
    }
    
    for(int i=0;i<H;i++)
    {
        nowsum = 0;
        closed = false;
        for(int j=0;j<W;j++)
        {
            if(map[i][j]==1 && closed==false)
            {
                closed = true;
            }
            else if(map[i][j]==1 && closed)
            {
                ret += nowsum;
                nowsum = 0;
            }
            if(map[i][j]!=1 && closed) nowsum++;
        }
    }
    
    printf("%d",ret);
    
    return 0;
}