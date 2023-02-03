# include <stdio.h>

int main()
{
    int n, i, j, k, count=0;
    scanf("%d",&n);
    n/=3;
    for(i=n-2;i>=1;i--)
    {
        for(j=n-i-1;j>=1;j--)
            count += 1;
    }
    printf("%d",count);
    return 0;
}