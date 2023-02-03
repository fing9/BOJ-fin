# include <stdio.h>
# include <string.h>
char map[103][103], now;
int cheak[103][103], ret1=0, ret2=0;
int paint=2;

void dfs_1(int x, int y){
    cheak[x][y]=1;
    if((map[x+1][y]=='R' || map[x+1][y]=='G') && cheak[x+1][y]==0){
        cheak[x+1][y]=1;
        dfs_1(x+1,y);
    }
    if((map[x][y+1]=='R' || map[x][y+1]=='G') && cheak[x][y+1]==0){
        cheak[x][y+1]=1;
        dfs_1(x,y+1);
    }
    if((map[x-1][y]=='R' || map[x-1][y]=='G') && cheak[x-1][y]==0){
        cheak[x-1][y]=1;
        dfs_1(x-1,y);
    }
    if((map[x][y-1]=='R' || map[x][y-1]=='G') && cheak[x][y-1]==0){
        cheak[x][y-1]=1;
        dfs_1(x,y-1);
    }
}

void dfs_2(int x, int y){
    cheak[x][y]=paint;
    if(map[x+1][y]==now && cheak[x+1][y]==0){
        cheak[x+1][y]=paint;
        dfs_2(x+1,y);
    }
    if(map[x][y+1]==now && cheak[x][y+1]==0){
        cheak[x][y+1]=paint;
        dfs_2(x,y+1);
    }
    if(map[x-1][y]==now && cheak[x-1][y]==0){
        cheak[x-1][y]=paint;
        dfs_2(x-1,y);
    }
    if(map[x][y-1]==now && cheak[x][y-1]==0){
        cheak[x][y-1]=paint;
        dfs_2(x,y-1);
    }
}

int main(){
    int N, i, j;
    scanf("%d",&N);
    
    for(i=0;i<103;i++){ // reset
        memset(map[i],NULL,sizeof(map[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    
    for(i=1;i<=N+1;i++){ // input
        for(j=1;j<=N+1;j++){
            scanf("%c",&map[i][j]);
        }
    }
    
    now='B';
    for(i=0;i<=N+1;i++){ // solve
        for(j=2;j<=N+1;j++){
            if((map[i][j]=='R' || map[i][j]=='G') && cheak[i][j]==0){
                dfs_1(i,j);
                ret1+=1;
            }
            if(map[i][j]==now && cheak[i][j]==0){
                dfs_2(i,j);
                ret1+=1;
            }
        }
    }
    
    for(i=0;i<103;i++) // reset
        memset(cheak[i],0,sizeof(cheak[i]));
    
    for(i=0;i<=N+1;i++){ // solve
        for(j=2;j<=N+1;j++){
            if(map[i][j]!=NULL){
                now=map[i][j];
                if(cheak[i][j]==0){
                    dfs_2(i,j);
                    paint+=1;
                    ret2+=1;
                }
            }
        }
    }
    
    printf("%d %d",ret2,ret1);
    
    return 0;
}