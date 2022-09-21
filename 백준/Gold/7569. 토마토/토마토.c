# include <stdio.h>
# include <string.h>
int box[103][103][103], cheak[103][103][103];
int queue[1100000][4], head=0, tail=0;
int M, N, H;
int dz[6] = {0,0,0,0,1,-1};
int dy[6] = {1,0,-1,0,0,0};
int dx[6] = {0,1,0,-1,0,0};
int maxt=-1;

int getmax(int x, int y){
    if(x>=y)
        return x;
    else
        return y;
}

void bfs(){
    int pz, py, px, pt, i;
    
    while(head<tail){
        pz=queue[head][0];
        py=queue[head][1];
        px=queue[head][2];
        pt=queue[head++][3];
        maxt=getmax(maxt,pt);

        for(i=0;i<6;i++){
            if(pz+dz[i]>0 && py+dy[i]>0 && px+dx[i]>0){
                if(box[pz+dz[i]][py+dy[i]][px+dx[i]]==0 && cheak[pz+dz[i]][py+dy[i]][px+dx[i]]==0){
                    queue[tail][0]=pz+dz[i];
                    queue[tail][1]=py+dy[i];
                    queue[tail][2]=px+dx[i];
                    queue[tail++][3]=pt+1;
                    cheak[pz+dz[i]][py+dy[i]][px+dx[i]]=1;
                }
            }
        }
    }
}

int main(){
    int i, j, l, isnot=0;
    scanf("%d %d %d",&M,&N,&H);
    
    for(i=0;i<103;i++){ // reset
        for(j=0;j<103;j++){
            for(l=0;l<103;l++){
                box[i][j][l]=-1;
            }
        }
    }
    for(i=0;i<103;i++){ // reset
        for(j=0;j<103;j++){
            memset(cheak[i][j],0,sizeof(cheak[i][j]));
        }
    }

    for(i=1;i<=H;i++){ // input
        for(j=1;j<=N;j++){
            for(l=1;l<=M;l++){
                scanf("%d",&box[i][j][l]);
                if(box[i][j][l]==1){
                    isnot+=1;
                    queue[tail][0]=i;
                    queue[tail][1]=j;
                    queue[tail][2]=l;
                    queue[tail++][3]=0;
                    cheak[i][j][l]=1;
                }
                if(box[i][j][l]==-1){
                    cheak[i][j][l]=-1;
                }
            }
        }
    }
    
    bfs(); // BFS
    
    for(i=1;i<=H;i++){
        for(j=1;j<=N;j++){
            for(l=1;l<=M;l++){
                if(cheak[i][j][l]==0){ // remain_tomato_cheak
                    printf("-1");
                    return 0;
                }
            }
        }
    }
    
    if(isnot==0){ // already_tomated
        printf("0");
        return 0;
    }

    printf("%d",maxt);

    return 0;
}