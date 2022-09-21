# include <stdio.h>
long long tree[4000000]={0,};
long long a[4000000]={0,};
long long answer=1000000001;

long long min(long long X, long long Y)
{
    if(X<=Y)
        return X;
    else
        return Y;
}

long long init(int node, int start, int end)
{
    if(start==end)
    {
        return tree[node] = a[start];
    }
    else
    {
        return tree[node] = min(init(node*2, start, (start+end)/2),init(node*2+1, (start+end)/2+1, end));
    }
}

long long small(int node, int start, int end, int left, int right)
{
    if(start>right || end<left)
        return 1000000001;
    if(start>=left && end<=right)
    {
        return tree[node];
    }
    return min(small(node*2,start,(start+end)/2,left,right),small(node*2+1,(start+end)/2+1,end,left,right));
}

int main()
{
    int N, M, i;
    int q, w;
    long long e;
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    init(1,1,N);
    for(i=0;i<M;i++)
    {
        answer=1000000001;
        scanf("%d %d",&q,&w);
        printf("%lld\n",small(1,1,N,q,w));
    }
    return 0;
}