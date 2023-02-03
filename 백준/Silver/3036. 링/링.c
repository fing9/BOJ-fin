# include <stdio.h>

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);
}

int main()
{
    int N, Num[101]={0,}, i;
    
    scanf("%d",&N);
    scanf("%d",&Num[0]);
    for(i=1;i<N;i++)
    {
        scanf("%d",&Num[i]);
        if(Num[0]==Num[i])
        {
            printf("1/1\n");
        }
        else if(Num[0]>Num[i])
        {
            printf("%d/%d\n",Num[0]/gcd(Num[0],Num[i]),Num[i]/gcd(Num[0],Num[i]));
        }
        else
        {
            printf("%d/%d\n",Num[0]/gcd(Num[i],Num[0]),Num[i]/gcd(Num[i],Num[0]));
        }
    }
    
    return 0;
}