# include <stdio.h>
# include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main()
{
    int N, K, i;
    scanf("%d %d",&N,&K);
    int A[N];
    
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    
    qsort(A, sizeof(A) / sizeof(int), sizeof(int), compare);
    
    printf("%d",A[K-1]);
    return 0;
}