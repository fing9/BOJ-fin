# include <stdio.h>
# include <string.h>
int map[103][103], cheak[103]={0,}, target_a, target_b, answer=0;
int queue[100000][2], head=0, tail=0;

void bfs(int node)
{
    int pop, popd, i, d=0;
    queue[tail][0]=node;
    queue[tail++][1]=d;
    cheak[node]=1;
    
    while(head<tail)
    {
        pop=queue[head][0];
        popd=queue[head++][1];
        
        for(i=1;i<=100;i++)
        {
            if(map[pop][i]==1 && i==target_b)
            {
                answer=popd+1;
                return;
            }
            if(map[pop][i]==1 && cheak[i]==0)
            {
                queue[tail][0]=i;
                queue[tail++][1]=popd+1;
                cheak[i]=1;
            }
        }
    }
}

int main()
{
    int n, m, i, j;
    int a, b;
    for(i=0;i<103;i++) // reset
        memset(map[i],0,sizeof(map[i]));
    for(i=0;i<100000;i++)
        memset(queue[i],0,sizeof(queue[i]));
    
    scanf("%d",&n);
    scanf("%d %d",&target_a,&target_b);
    scanf("%d",&m);
    for(i=0;i<m;i++) // input
    {
        scanf("%d %d",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
    }
    
    bfs(target_a);
    
    if(answer!=0) // output
        printf("%d",answer);
    else
        printf("-1");
    
    return 0;
}