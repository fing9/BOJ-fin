# include <stdio.h>
# include <string.h>
int map[202][202], cheak[202][202][32];
int queue[1300000][4], head=0, tail=0;
int tx[8]={1,2,-1,-2,1,2,-1,-2};
int ty[8]={2,1,2,1,-2,-1,-2,-1};
int mx[4]={1,0,-1,0};
int my[4]={0,1,0,-1};
int K, W, H, answer=-1;

void bfs(int x, int y){
    int px, py, pd, pt, i, j;
    queue[tail][0]=x;
    queue[tail][1]=y;
    queue[tail][2]=0;
    queue[tail++][3]=0;
    cheak[x][y][0]=1;
    
    while(head<tail){
        px=queue[head][0];
        py=queue[head][1];
        pd=queue[head][2];
        pt=queue[head++][3];
        if(px==W-1 && py==H-1){
            answer=pt;
            return;
        }
        if(pd<K){
            for(i=0;i<8;i++){
                if(px+tx[i]>-1 && py+ty[i]>-1 && px+tx[i]<W && py+ty[i]<H){
                    if(map[py+ty[i]][px+tx[i]]==0 && cheak[py+ty[i]][px+tx[i]][pd+1]==0){
                        queue[tail][0]=px+tx[i];
                        queue[tail][1]=py+ty[i];
                        queue[tail][2]=pd+1;
                        queue[tail++][3]=pt+1;
                        cheak[py+ty[i]][px+tx[i]][pd+1]=1;
                    }
                }
            }
        }
        for(j=0;j<4;j++){
             if(px+mx[j]>-1 && py+my[j]>-1 && px+mx[j]<W && py+my[j]<H){
                if(map[py+my[j]][px+mx[j]]==0 && cheak[py+my[j]][px+mx[j]][pd]==0){
                    queue[tail][0]=px+mx[j];
                    queue[tail][1]=py+my[j];
                    queue[tail][2]=pd;
                    queue[tail++][3]=pt+1;
                    cheak[py+my[j]][px+mx[j]][pd]=1;
                }
            }
        }
    }
}

int main(){
    int i, j;
    scanf("%d",&K);
    scanf("%d %d",&W,&H);
    
    for(i=0;i<202;i++){ // reset
        for(j=0;j<202;j++){
            map[i][j]=1;
        }
    }
    for(i=0;i<202;i++){
        for(j=0;j<202;j++)
            memset(cheak[i][j],0,sizeof(cheak[i][j]));
    }
    
    for(i=0;i<H;i++){ // input
        for(j=0;j<W;j++)
            scanf("%d",&map[i][j]);
    }
    
    if(H==1 && W==1){ // 예외
        printf("0");
        return 0;
    }
    
    bfs(0,0); // bfs
    
    printf("%d",answer); // answer
    
    return 0;
}