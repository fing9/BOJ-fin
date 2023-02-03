# include <stdio.h>
long long A, B, C;

long long solve(long long mid)
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
            return (solve(mid/2) * solve(mid/2)) % C;
        else
            return (((solve(mid/2) * solve(mid/2)) % C) * solve(1)) % C;
    }
}

int main()
{
    long long answer=0;
    scanf("%lld %lld %lld",&A,&B,&C);
    
    printf("%lld",solve(B));
    
    return 0;
}