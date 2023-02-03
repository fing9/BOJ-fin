# include <stdio.h>

int min(int x, int y)
{
    if(x<=y)
        return x;
    else
        return y;
}

int main()
{
    int b[3], c[2], i, j, answer=8000;
    scanf("%d",&b[0]);
    scanf("%d",&b[1]);
    scanf("%d",&b[2]);
    scanf("%d",&c[0]);
    scanf("%d",&c[1]);
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
            answer=min(answer,b[i]+c[j]-50);
    }
    
    printf("%d",answer);
    return 0;
}