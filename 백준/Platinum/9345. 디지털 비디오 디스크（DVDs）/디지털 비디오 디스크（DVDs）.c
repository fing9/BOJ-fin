# include <stdio.h>
long long tree[400000], a[400000], max=-1, min=1000000;
long long mintree[400000];

long long gmax(long long x, long long y)
{
    if(x>=y)
        return x;
    else
        return y;
}

long long gmin(long long x, long long y)
{
    if(x<=y)
        return x;
    else
        return y;
}

long long init(int node, int start, int end)
{
    if(start==end)
    {
        return tree[node] = a[start];
    }
    else
    {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = gmax(tree[node*2],tree[node*2+1]);
    }
}

long long mininit(int node, int start, int end)
{
    if(start==end)
    {
        return mintree[node] = a[start];
    }
    else
    {
        mininit(node*2, start, (start+end)/2);
        mininit(node*2+1, (start+end)/2+1, end);
        mintree[node] = gmin(mintree[node*2],mintree[node*2+1]);
    }
}

void update(int node, int start, int end, int index, long long df)
{
    if(start>index || end<index)
        return;
    if(start!=end)
    {
        update(node*2,start,(start+end)/2,index,df);
        update(node*2+1,(start+end)/2+1,end,index,df);
        tree[node] = gmax(tree[node*2],tree[node*2+1]);
    }
    else
    {
        tree[node] = df;
    }
}

void minupdate(int node, int start, int end, int index, long long df)
{
    if(start>index || end<index)
        return;
    if(start!=end)
    {
        minupdate(node*2,start,(start+end)/2,index,df);
        minupdate(node*2+1,(start+end)/2+1,end,index,df);
        mintree[node] = gmin(mintree[node*2],mintree[node*2+1]);
    }
    else
    {
        mintree[node] = df;
    }
}

void maxq(int node, int start, int end, int left, int right)
{
    if(start>right || end<left)
        return;
    if(start>=left && end<=right)
    {
        max = gmax(max,tree[node]);
        return;
    }
    maxq(node*2,start,(start+end)/2,left,right);
    maxq(node*2+1,(start+end)/2+1,end,left,right);
}

void minq(int node, int start, int end, int left, int right)
{
    if(start>right || end<left)
        return;
    if(start>=left && end<=right)
    {
        min = gmin(min,mintree[node]);
        return;
    }
    minq(node*2,start,(start+end)/2,left,right);
    minq(node*2+1,(start+end)/2+1,end,left,right);
}

int main(){
    int T, N, K, i, j;
    int q, w, e, tmp;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&K);
        for(i=1;i<N+2;i++)
            a[i]=i-1;
        init(1,1,N+1);
        mininit(1,1,N+1);
        for(i=0;i<K;i++){
            max=-1;
            min=1000000;
            scanf("%d %d %d",&q,&w,&e);
            w++;
            e++;
            if(q==0){
                update(1,1,N+1,w,a[e]);
                update(1,1,N+1,e,a[w]);
                minupdate(1,1,N+1,w,a[e]);
                minupdate(1,1,N+1,e,a[w]);
                tmp=a[w];
                a[w]=a[e];
                a[e]=tmp;
            }
            else{
                maxq(1,1,N+1,w,e);
                minq(1,1,N+1,w,e);
                if(min==w-1 && max==e-1){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
        }
    }
    
    return 0;
}