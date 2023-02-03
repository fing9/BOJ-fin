# include <stdio.h>
# include <string.h>
int map[400][400], cheak[400][400];
int queue[10000000][3], head=0, tail=0;
int t, l, sx, sy, lx, ly, answer=0;
int tx[8]={1,2,-1,-2,1,2,-1,-2};
int ty[8]={2,1,2,1,-2,-1,-2,-1};

void dfs(int x, int y){
    int px, py, pd, i;
    queue[tail][0]=x;
    queue[tail][1]=y;
    queue[tail++][2]=1;
    cheak[x][y]=1;
    
    while(head<tail){
        px=queue[head][0];
        py=queue[head][1];
        pd=queue[head++][2];
        if(px==lx && py==ly){
            answer=pd;
            return;
        }
        for(i=0;i<8;i++){
            if(px+tx[i]>-1 && py+ty[i]>-1 && px+tx[i]<l && py+ty[i]<l){
                if(cheak[px+tx[i]][py+ty[i]]==0){
                    queue[tail][0]=px+tx[i];
                    queue[tail][1]=py+ty[i];
                    queue[tail++][2]=pd+1;
                    cheak[px+tx[i]][py+ty[i]]=pd+1;
                }
            }
        }
    }
}

int main(){
    int i, j;
    scanf("%d",&t);
    while(t--){
        head=0;
        tail=0;
        for(i=0;i<400;i++){
            memset(map[i],0,sizeof(map[i]));
            memset(cheak[i],0,sizeof(cheak[i]));
        }
        answer=0;
        scanf("%d",&l);
        scanf("%d %d",&sx,&sy);
        map[sx][sy]=1;
        map[sy][sx]=1;
        scanf("%d %d",&lx,&ly);
        map[lx][ly]=1;
        map[ly][lx]=1;
        if(sx==lx && sy==ly){
            printf("0\n");
        }
        else{
            dfs(sx,sy);
            printf("%d\n",answer-1);
        }
    }
    
    return 0;
}