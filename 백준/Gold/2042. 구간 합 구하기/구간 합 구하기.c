# include <stdio.h>
long long tree[4000000]={0,};
long long a[4000000]={0,};

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

void update(int node, int start, int end, int index, long long df)
{
    if(start>index || end<index)
        return;
    tree[node] += df;
    if(start!=end)
    {
        update(node*2,start,(start+end)/2,index,df);
        update(node*2+1,(start+end)/2+1,end,index,df);
    }
}

long long sum(int node, int start, int end, int left, int right)
{
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
    int N, M, K, i;
    int q, w;
    long long e;
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
            update(1,1,N,w,e-a[w]);
            a[w] = e;
        }
        else
        {
            j=(int)e;
            printf("%lld\n",sum(1,1,N,w,j));
        }
    }
    return 0;
}