# include <stdio.h>
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
    int N, i;
    
    scanf("%d",&N);
    int Num[N];
    for(i=0;i<N;i++){
        scanf("%d",&Num[i]);
    }
    
    qsort(Num,N,sizeof(int),compare);
    
    for(i=0;i<N;i++){
        if(i!=N-1)
            printf("%d\n",Num[i]);
        else
            printf("%d",Num[i]);
    }
    
    return 0;
}