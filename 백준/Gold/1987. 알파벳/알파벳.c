# include <stdio.h>
# include <string.h>
int cheak[22][22], ap_cheak[30]={0,}, max=1;
char map[22][22], trans[22][22];

void dfs(int x, int y, int depth)
{
    if(max<depth)
        max=depth;
    
    if(map[x+1][y]!=NULL && cheak[x+1][y]==0 && ap_cheak[map[x+1][y]-65]==0)
    {
        cheak[x+1][y]=1;
        ap_cheak[map[x+1][y]-65]++;
        dfs(x+1,y,depth+1);
        cheak[x+1][y]=0;
        ap_cheak[map[x+1][y]-65]--;
    }
    if(map[x][y+1]!=NULL && cheak[x][y+1]==0 && ap_cheak[map[x][y+1]-65]==0)
    {
        cheak[x][y+1]=1;
        ap_cheak[map[x][y+1]-65]++;
        dfs(x,y+1,depth+1);
        cheak[x][y+1]=0;
        ap_cheak[map[x][y+1]-65]--;
    }
    if(map[x-1][y]!=NULL && cheak[x-1][y]==0 && ap_cheak[map[x-1][y]-65]==0)
    {
        cheak[x-1][y]=1;
        ap_cheak[map[x-1][y]-65]++;
        dfs(x-1,y,depth+1);
        cheak[x-1][y]=0;
        ap_cheak[map[x-1][y]-65]--;
    }
    if(map[x][y-1]!=NULL && cheak[x][y-1]==0 && ap_cheak[map[x][y-1]-65]==0)
    {
        cheak[x][y-1]=1;
        ap_cheak[map[x][y-1]-65]++;
        dfs(x,y-1,depth+1);
        cheak[x][y-1]=0;
        ap_cheak[map[x][y-1]-65]--;
    }
}

int main()
{
    int i, j;
    int R, C;
    for(i=0;i<22;i++)
    {
        memset(map[i],NULL,sizeof(map[i]));
        memset(trans[i],NULL,sizeof(trans[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    memset(ap_cheak,0,sizeof(ap_cheak));
    
    scanf("%d %d",&R,&C);
    
    for(i=1;i<=R;i++)
    {
        scanf("%s",&trans[i]);
    }
    
    for(i=1;i<=R;i++)
    {
        for(j=0;j<C;j++)
            map[i][j+1]=trans[i][j];
    }
        
    cheak[1][1]=1;
    ap_cheak[map[1][1]-65]++;
    
    dfs(1,1,1);
    
    printf("%d",max);
    
    return 0;
}