# include <stdio.h>

int main()
{
    int A[5],i,sum=0;
    for(i=0;i<5;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]<40)
            sum+=40;
        else
            sum+=A[i];
    }
    printf("%d",sum/5);
    return 0;
}