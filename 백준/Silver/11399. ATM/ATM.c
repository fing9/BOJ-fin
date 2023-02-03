# include <stdio.h>

int main()
{
    int N, i, j, tmp, answer=0;
    scanf("%d",&N);
    int time[N];
    for(i=0;i<N;i++)
        scanf("%d",&time[i]);
    
    for(i=0;i<N-1;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(time[i]>time[j])
            {
                tmp = time[i];
                time[i] = time[j];
                time[j] = tmp;
            }
        }
    }
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<=i;j++)
            answer += time[j];
    }
    printf("%d",answer);
    return 0;
}