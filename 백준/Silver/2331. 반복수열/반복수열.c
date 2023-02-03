# include <stdio.h>

int main()
{
    int A, P, answer=0, num[300000]={0,}, start, tmpsum=0, tmp=1, i;
    int end;
    scanf("%d %d",&A,&P);
    start=A;
    while(1)
    {
        if(num[A]==1)
        {
            end=A;
            A=start;
            while(A!=end)
            {
                answer++;
                while(A>0)
                {
                    for(i=0;i<P;i++)
                        tmp*=A%10;
                    tmpsum+=tmp;
                    tmp=1;
                    A/=10;
                }
                A=tmpsum;
                tmpsum=0;
            }
            break;
        }
        else
        {
            num[A]=1;
            while(A>0)
            {
                for(i=0;i<P;i++)
                    tmp*=A%10;
                tmpsum+=tmp;
                tmp=1;
                A/=10;
            }
            A=tmpsum;
            tmpsum=0;
        }
    }
    
    printf("%d",answer);
    return 0;
}