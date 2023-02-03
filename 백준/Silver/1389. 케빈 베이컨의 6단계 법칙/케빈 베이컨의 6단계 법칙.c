# include <stdio.h>
# include <string.h>
int tree[103][103], cheak[103]={0,}, answer[103]={0,};
int queue[100000][2], head=0, tail=0;
int N, M, now;

void bfs(int node){
    int pop, popd, i;
    queue[tail][0]=node;
    queue[tail++][1]=0;
    cheak[node]=1;
    
    while(head<tail){
        pop=queue[head][0];
        popd=queue[head++][1];
        
        for(i=1;i<103;i++){
            if(tree[pop][i]==1 && cheak[i]==0){
                queue[tail][0]=i;
                queue[tail++][1]=popd+1;
                answer[now]+=popd+1;
                cheak[i]=1;
            }
        }
    }
}

int main(){
    int a, b, i, j, k, ret=1000000000, retnode=0;
    
    for(i=0;i<103;i++) // reset
        memset(tree[i],0,sizeof(tree[i]));
    
    scanf("%d %d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        
        tree[a][b] = 1;
        tree[b][a] = 1;
    }
    
    for(i=1;i<103;i++){
        for(k=1;k<103;k++){
            if(tree[i][k]==1){
                now=i;
                bfs(i);
                memset(cheak,0,sizeof(cheak));
                head=0;
                tail=0;
                k=104;
            }
        }
    }
    
    for(i=0;i<103;i++){
        if(answer[i]<ret && answer[i]!=0){
            ret=answer[i];
            retnode=i;
        }
    }
    
    printf("%d",retnode);
    
    return 0;
}