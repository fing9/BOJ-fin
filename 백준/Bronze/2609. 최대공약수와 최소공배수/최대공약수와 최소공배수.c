# include <stdio.h>

int main()
{
    int A, B, a2, b2, max, min, i;
    scanf("%d %d",&A,&B);
    
    a2=A;
    b2=B;
    
    if(A==B)
        min = A;
    else if(A>B)
    {
        for(i=B;i>=1;i--)
        {
            if(A%i==0 && B%i==0)
            {
                min = i;
                break;
            }
        }
    }
    else
    {
        for(i=A;i>=1;i--)
        {
            if(A%i==0 && B%i==0)
            {
                min = i;
                break;
            }
        }
    }
    
    printf("%d\n",min);
    
    while(1)
    {
        if(a2==b2)
        {
            max = a2;
            break;
        }
        else if(a2>b2)
            b2 += B;
        else
            a2 += A;
    }
    
    printf("%d",max);
    
    return 0;
}