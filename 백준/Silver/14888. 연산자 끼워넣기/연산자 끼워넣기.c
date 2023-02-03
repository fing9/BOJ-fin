# include <stdio.h>
int N, num[101];
int pl, mn, mt, dv;
int max=-1000000000;
int min=1000000000;

int gmax(int x, int y)
{
    if(x>=y)
        return x;
    else
        return y;
}

int gmin(int x, int y)
{
    if(x<=y)
        return x;
    else
        return y;
}

void solve(int d, int now, int p, int n, int t, int v)
{
    if(d==N-1)
    {
        max = gmax(max,now);
        min = gmin(min,now);
        return;
    }
    else
    {
        if(pl>p)
        {
            solve(d+1,now+num[d+1],p+1,n,t,v);
        }
        if(mn>n)
        {
            solve(d+1,now-num[d+1],p,n+1,t,v);
        }
        if(mt>t)
        {
            solve(d+1,now*num[d+1],p,n,t+1,v);
        }
        if(dv>v)
        {
            solve(d+1,now/num[d+1],p,n,t,v+1);
        }
    }
}

int main()
{
    int i, j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&num[i]);
    scanf("%d %d %d %d",&pl,&mn,&mt,&dv);
    
    solve(0,num[0],0,0,0,0);
    
    printf("%d\n%d",max,min);
    
    return 0;
}