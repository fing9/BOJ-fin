# include <stdio.h>

int main()
{
    int A=1, B=1;
    while(1)
    {
        scanf("%d %d",&A,&B);
        if(A==0 && B==0)
            break;
        if(B%A==0)
            printf("factor\n");
        else if(A%B==0)
            printf("multiple\n");
        else
            printf("neither\n");
    }
    return 0;
}