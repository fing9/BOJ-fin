# include <stdio.h>
# include <string.h>
char map[40][40][40];
int cheak[40][40][40];
int queue[1000000][4], head=0, tail=0;
int L, R, C, answer=-1;
int dz[6] = {0,0,0,0,1,-1};
int dy[6] = {1,0,-1,0,0,0};
int dx[6] = {0,1,0,-1,0,0};
int edz, edy, edx;

void bfs(int z, int y, int x){
    int pz, py, px, pd, i;
    queue[tail][0]=z;
    queue[tail][1]=y;
    queue[tail][2]=x;
    queue[tail++][3]=0;
    cheak[z][y][x]=1;
    
    while(head<tail){
        pz=queue[head][0];
        py=queue[head][1];
        px=queue[head][2];
        pd=queue[head++][3];
        
        if(pz==edz && py==edy && px==edx){
            answer=pd;
            return;
        }
        
        for(i=0;i<6;i++){
            if(pz+dz[i]>-1 && py+dy[i]>-1 && px+dx[i]>-1 && pz+dz[i]<L && py+dy[i]<R && px+dx[i]<C){
                if((map[pz+dz[i]][py+dy[i]][px+dx[i]]=='.' || map[pz+dz[i]][py+dy[i]][px+dx[i]]=='E') && cheak[pz+dz[i]][py+dy[i]][px+dx[i]]==0){
                    queue[tail][0]=pz+dz[i];
                    queue[tail][1]=py+dy[i];
                    queue[tail][2]=px+dx[i];
                    queue[tail++][3]=pd+1;
                    cheak[pz+dz[i]][py+dy[i]][px+dx[i]]=1;
                }
            }
        }
    }
}

int main(){
    int i, j, l;
    int a, b, c;
    scanf("%d %d %d",&L,&R,&C);
    
    while(L!=0 || R!=0 || C!=0){
        answer=-1;
        head=0;
        tail=0;
        for(i=0;i<40;i++){ // reset
            for(j=0;j<40;j++){
                memset(map[i][j],'#',sizeof(map[i][j]));
                memset(cheak[i][j],0,sizeof(cheak[i][j]));
            }
        }
        
        for(i=0;i<L;i++){
            for(j=0;j<R;j++){
                scanf("%s",map[i][j]);
            }
        }
        
        for(i=0;i<L;i++){ // get_start_point & end_point
            for(j=0;j<R;j++){
                for(l=0;l<C;l++){
                    if(map[i][j][l]=='S'){
                        a=i;
                        b=j;
                        c=l;
                    }
                    if(map[i][j][l]=='E'){
                        edz=i;
                        edy=j;
                        edx=l;
                    }
                }
            }
        }
        
        bfs(a,b,c);
        
        if(answer!=-1){
            printf("Escaped in %d minute(s).\n",answer);
        }
        else{
            printf("Trapped!\n");
        }
        
        scanf("%d %d %d",&L,&R,&C);
    }
    
    return 0;
}