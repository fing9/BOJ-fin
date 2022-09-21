# include <stdio.h>
# include <math.h>
int N, ches[16]={0,}, answer=0;

int promising(int i)
{
    int j;
    for(j=0;j<i;j++)
    {
        if(ches[j] == ches[i] || abs(ches[i]-ches[j]) == (i-j))
            return 0;
    }
    return 1;
}


void N_Queen(int i)
{
    if(i == N)
        answer++;
    else
    {
        for(int j=0;j<N;j++)
        {
            ches[i] = j;
            if(promising(i))
                N_Queen(i+1);
        }
    }
}


int main()
{
    scanf("%d",&N);
    
    N_Queen(0);
    
    printf("%d",answer);
    return 0;
} //왜이렇게 어려운건데..