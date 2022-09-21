# include <stdio.h>
long long tree[4000000]={0,};
long long a[4000000]={0,};
long long lazy[4000000]={0,};

long long init(int node, int start, int end)
{
    if(start==end)
    {
        return tree[node] = a[start];
    }
    else
    {
        return tree[node] = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
    }
}

void update(int node, int start, int end, int left, int right, long long pls)
{
    propagation(node, start, end);
    if(start>right || end<left)
        return;
    if(start>=left && end<=right)
    {
        tree[node] += (end-start+1)*pls;
        if(start!=end)
        {
            lazy[node*2] += pls;
            lazy[node*2+1] += pls;
        }
        return;
    }
    update(node*2,start,(start+end)/2,left,right,pls);
    update(node*2+1,(start+end)/2+1,end,left,right,pls);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void propagation(int node, int start, int end)
{
    if(lazy[node]!=0)
    {
        tree[node] += (end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

long long sum(int node, int start, int end, int left, int right)
{
    propagation(node,start,end);
    if(start>right || end<left)
        return 0;
    if(start>=left && end<=right)
    {
        return tree[node];
    }
    return sum(node*2,start,(start+end)/2,left,right) + sum(node*2+1,(start+end)/2+1,end,left,right);
}

int main()
{
    int N, M, K, i, l;
    int q, w;
    long long e, r;
    int j;
    scanf("%d %d %d",&N,&M,&K);
    for(i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    init(1,1,N);
    for(i=0;i<M+K;i++)
    {
        scanf("%d %d %lld",&q,&w,&e);
        if(q==1)
        {
            scanf("%lld",&r);
            update(1,1,N,w,e,r);
        }
        else
        {
            j=(int)e;
            printf("%lld\n",sum(1,1,N,w,j));
        }
    }
    return 0;
}