# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int compare(const void *first, const void *second)
{
    int num1 = *(int *)first;
    int num2 = *(int *)second;
    
    if(num1 < num2)
        return 1;
    if(num1 > num2)
        return -1;
    
    return 0;
}

int main()
{
    int N, A, B, i, j, istile, Yebbm=0;
    scanf("%d %d %d",&N,&A,&B);
    int tile1[A+1], tile2[B+1];
    memset(tile1,0,sizeof(tile1));
    memset(tile2,0,sizeof(tile2));
    for(i=0;i<A;i++)
        scanf("%d",&tile1[i]);
    for(i=0;i<B;i++)
        scanf("%d",&tile2[i]);
    qsort(tile1,A,sizeof(int),compare); //내림차순정렬
    qsort(tile2,B,sizeof(int),compare);
    
    i=0; //tile1의 인덱스
    j=0; //tile2의 인덱스
    istile=0;
    if(N%2 == 1)
    {
        Yebbm+=tile1[i++];
        N-=1;
    }
    else if(N==2)
    {
        if(tile1[0]+tile1[1]<tile2[0])
        {
            printf("%d",tile2[0]);
            return 0;
        }
        else
        {
            printf("%d",tile1[0]+tile1[1]);
            return 0;
        }
    }
    while(istile<N)
    {
        if(tile1[i]+tile1[i+1]>=tile2[j] && istile+2<N+1 && tile1[i+1]!=0 && tile1[i]!=0)
        {
            Yebbm+=tile1[i++];
            Yebbm+=tile1[i++];
            istile+=2;
        }
        else
        {
            Yebbm+=tile2[j++];
            istile+=2;
        }
    }
    printf("%d",Yebbm);
}