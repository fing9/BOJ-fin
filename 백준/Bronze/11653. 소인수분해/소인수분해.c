# include <stdio.h>

int main()
{
    int N, i, judge=2;
    scanf("%d",&N);
    while(N>1)
    {
        if(N%judge==0)
        {
            N /= judge;
            printf("%d\n",judge);
        }
        else
            judge++;
    }
    return 0;
}