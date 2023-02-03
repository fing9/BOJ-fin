# include <stdio.h>
long long tree[4000000]={0,}, a[4000000]={0,};

long long init(int node, int start, int end){
    if(start==end)
    {
        return tree[node] = a[start];
    }
    else
    {
        return tree[node] = (init(node*2, start, (start+end)/2) * init(node*2+1, (start+end)/2+1, end)) % 1000000007;
    }
}

long long update(int node, int start, int end, int index, long long mt){
    if(start>index || end<index)
        return tree[node];
    
    if(start==end && start==index){
        return tree[node] = mt;
    }
    else{
        return tree[node] = (update(node*2,start,(start+end)/2,index,mt) * update(node*2+1,(start+end)/2+1,end,index,mt)) % 1000000007;
    }
}

long long multy(int node, int start, int end, int left, int right){
    if(start>right || end<left)
        return 1;
    if(start>=left && end<=right)
    {
        return tree[node];
    }
    return (multy(node*2,start,(start+end)/2,left,right) * multy(node*2+1,(start+end)/2+1,end,left,right)) % 1000000007;
}

int main(){
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
            update(1,1,N,w,e);
            a[w] = e;
        }
        else
        {
            j=(int)e;
            printf("%lld\n",multy(1,1,N,w,j)%1000000007);
        }
    }
    return 0;
}