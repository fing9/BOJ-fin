# include <stdio.h>

int main()
{
    int N, i=0, j, Max, tmp, sum=0, Num[11];
    scanf("%d",&N);
    while(N>=10)
    {
        Num[i++]=N%10;
        N/=10;
    }
    if(N<10)
        Num[i++]=N;

    Max=i;
    for(i=0;i<Max-1;i++)
    {
        for(j=i+1;j<Max;j++)
        {
            if(Num[i]<Num[j])
            {
                tmp = Num[i];
                Num[i] = Num[j];
                Num[j] = tmp;
            }
        }
    }
    
    for(i=0;i<Max;i++)
    {
        sum += Num[i];
        if(i!=Max-1)
            sum*=10;
    }
    printf("%d",sum);
    return 0;
}