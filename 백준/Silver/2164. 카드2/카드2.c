# include <stdio.h>

int main()
{
    int queue[2000002]={0,}, head=1000000, tail=1000000;
    int N, i, j;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        queue[tail++]=i;
    
    while(tail-head != 1)
    {
        head++;
        queue[tail++]=queue[head++];
    }
    
    printf("%d",queue[head]);
    
    return 0;
}