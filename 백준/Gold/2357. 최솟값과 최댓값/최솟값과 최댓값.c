# include <stdio.h>
long long tree_max[4000000]={0,};
long long tree_min[4000000]={0,};
long long a[4000000]={0,};

long long max(long long X, long long Y)
{
    if(X>=Y)
        return X;
    else
        return Y;
}

long long min(long long X, long long Y)
{
    if(X<=Y)
        return X;
    else
        return Y;
}

long long init_max(int node, int start, int end)
{
    if(start==end)
    {
        return tree_max[node] = a[start];
    }
    else
    {
        return tree_max[node] = max(init_max(node*2, start, (start+end)/2),init_max(node*2+1, (start+end)/2+1, end));
    }
}

long long init_min(int node, int start, int end)
{
    if(start==end)
    {
        return tree_min[node] = a[start];
    }
    else
    {
        return tree_min[node] = min(init_min(node*2, start, (start+end)/2),init_min(node*2+1, (start+end)/2+1, end));
    }
}

long long small(int node, int start, int end, int left, int right)
{
    if(start>right || end<left)
        return 1000000001;
    if(start>=left && end<=right)
    {
        return tree_min[node];
    }
    return min(small(node*2,start,(start+end)/2,left,right),small(node*2+1,(start+end)/2+1,end,left,right));
}

long long large(int node, int start, int end, int left, int right)
{
    if(start>right || end<left)
        return -1000000001;
    if(start>=left && end<=right)
    {
        return tree_max[node];
    }
    return max(large(node*2,start,(start+end)/2,left,right),large(node*2+1,(start+end)/2+1,end,left,right));
}


int main()
{
    int N, M, i;
    int q, w;
    long long e;
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    init_max(1,1,N);
    init_min(1,1,N);
    for(i=0;i<M;i++)
    {
        scanf("%d %d",&q,&w);
        printf("%lld %lld\n",small(1,1,N,q,w),large(1,1,N,q,w));
    }
    return 0;
}