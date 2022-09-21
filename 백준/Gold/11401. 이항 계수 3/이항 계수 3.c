# include <stdio.h>
long long C = 1000000007;
long long N, K;

long long solve2(long long start, long long end)
{
    long long mid = start+((end-start)/2);
    if(start==end && end!=0)
    {
        return end;
    }
    else
    {
        return (solve2(start,mid) * solve2(mid+1,end)) % C;
    }
}

long long solve(long long mid, long long A)
{
    if(mid==2)
    {
        return (A*A)%C;
    }
    else if(mid==1)
    {
        return A%C;
    }
    else
    {
        if(mid%2==0)
            return (solve(mid/2,A) * solve(mid/2,A)) % C;
        else
            return (((solve(mid/2,A) * solve(mid/2,A)) % C) * solve(1,A)) % C;
    }
}

int main()
{
    long long rt;
    scanf("%lld %lld",&N,&K);
    
    if(N==K)
    {
        printf("1");
        return 0;
    }
    else if(K==0)
    {
        printf("1");
        return 0;
    }
    
    rt = (solve2(1,N) * solve(C-2,(solve2(1,K) * solve2(1,(N-K))) % C)) % C;
    
    printf("%lld",rt);
    
    return 0;
}