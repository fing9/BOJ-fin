# include <stdio.h>
# include <stdlib.h>
# include <string.h>

long long int compare(const void *a, const void *b)    // 오름차순
{
    long long int num1 = *(long long int *)a;
    long long int num2 = *(long long int *)b;
    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}


int main()
{
    long long int answer;
    int max_num=1;
    int time_num=1, N, i;
    
    scanf("%d",&N);
    long long int Num[N];
    for(i=0;i<N;i++)
    {
        scanf("%lld",&Num[i]);
    }
    qsort(Num, sizeof(Num) / sizeof(long long int), sizeof(long long int), compare);
    
    answer=Num[0];
    
    for(i=1;i<N;i++)
    {
        if(Num[i]==Num[i-1])
        {
            time_num++;
        }
        else
        {
            time_num=1;
        }
        
        if(time_num>max_num)
        {
            max_num=time_num;
            answer=Num[i];
        }
        
    }
    printf("%lld",answer);
    
    return 0;
}