# include <stdio.h>
# include <string.h>
char map[1002][1002];
int cheak[1002][1002][2];
int queue[3000000][4], head=0, tail=0;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int N, M, ret=1000000000;

int getmin(int x, int y){
    if(x<=y)
        return x;
    else
        return y;
}

void bfs(){
    int py, px, pd, pp;
    
    queue[tail][0]=0;
    queue[tail][1]=0;
    queue[tail][2]=1;
    queue[tail++][3]=0;
    cheak[0][0][0]=1;
    
    while(head<tail){
        py=queue[head][0];
        px=queue[head][1];
        pd=queue[head][2];
        pp=queue[head++][3];
        
        if(py==N-1 && px==M-1)
            ret=getmin(pd,ret);
        
        for(int i=0;i<4;i++){
            if(py+dy[i]>-1 && px+dx[i]>-1 && py+dy[i]<N && px+dx[i]<M){
                if(pp!=0){
                    if(map[py+dy[i]][px+dx[i]]=='0' && cheak[py+dy[i]][px+dx[i]][1]==0){
                        queue[tail][0]=py+dy[i];
                        queue[tail][1]=px+dx[i];
                        queue[tail][2]=pd+1;
                        queue[tail++][3]=pp;
                        cheak[py+dy[i]][px+dx[i]][1]=1;
                    }
                }
                else{
                    if(map[py+dy[i]][px+dx[i]]=='0' && cheak[py+dy[i]][px+dx[i]][0]==0){
                        queue[tail][0]=py+dy[i];
                        queue[tail][1]=px+dx[i];
                        queue[tail][2]=pd+1;
                        queue[tail++][3]=pp;
                        cheak[py+dy[i]][px+dx[i]][0]=1;
                    }
                    if(map[py+dy[i]][px+dx[i]]=='1' && cheak[py+dy[i]][px+dx[i]][1]==0){
                        queue[tail][0]=py+dy[i];
                        queue[tail][1]=px+dx[i];
                        queue[tail][2]=pd+1;
                        queue[tail++][3]=pp+1;
                        cheak[py+dy[i]][px+dx[i]][1]=1;
                    }
                }
            }
        }
    }
}

int main(){
    int i, j;
    for(i=0;i<1002;i++){ // reset_map
        for(j=0;j<1002;j++){
            map[i][j]='2';
        }
    }
    for(i=0;i<1002;i++){ // reset_cheak
        for(j=0;j<1002;j++)
            memset(cheak[i][j],0,sizeof(cheak[i][j]));
    }
    
    scanf("%d %d",&N,&M); // input
    for(i=0;i<N;i++){
        scanf("%s",map[i]);
    }
    
    bfs();
    
    if(ret!=1000000000)
        printf("%d",ret);
    else
        printf("-1");
    
    return 0;
}