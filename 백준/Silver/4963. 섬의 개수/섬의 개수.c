# include <stdio.h>
# include <string.h>
int map[53][53], cheak[53][53], answer=0;

void dps(int x, int y)
{
    cheak[x][y]=1;
    
    if(map[x+1][y]==1 && cheak[x+1][y]==0)
        dps(x+1,y);
    if(map[x][y+1]==1 && cheak[x][y+1]==0)
        dps(x,y+1);
    if(map[x-1][y]==1 && cheak[x-1][y]==0)
        dps(x-1,y);
    if(map[x][y-1]==1 && cheak[x][y-1]==0)
        dps(x,y-1);
    if(map[x+1][y+1]==1 && cheak[x+1][y+1]==0)
        dps(x+1,y+1);
    if(map[x-1][y+1]==1 && cheak[x-1][y+1]==0)
        dps(x-1,y+1);
    if(map[x+1][y-1]==1 && cheak[x+1][y-1]==0)
        dps(x+1,y-1);
    if(map[x-1][y-1]==1 && cheak[x-1][y-1]==0)
        dps(x-1,y-1);
}

int main()
{
    int w, h;
    int i, j;
    
    scanf("%d %d",&w,&h);
    while(w!=0 && h!=0)
    {
        for(i=0;i<=52;i++) //reset
        {
            memset(map[i],0,sizeof(map[i]));
            memset(cheak[i],0,sizeof(cheak[i]));
        }
        answer=0;
        
        for(i=1;i<=h;i++) //input
        {
            for(j=1;j<=w;j++)
                scanf("%d",&map[i][j]);
        }
        
        for(i=1;i<=h;i++) //solve
        {
            for(j=1;j<=w;j++)
            {
                if(map[i][j]==1 && cheak[i][j]==0)
                {
                    dps(i,j);
                    answer++;
                }
            }
        }
        
        printf("%d\n",answer); //output
        scanf("%d %d",&w,&h);
    }
}