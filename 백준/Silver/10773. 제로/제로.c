# include <stdio.h>

int main()
{
    int stack[100001], l=0, num, answer=0, N, i;
    scanf("%d",&N);
    
    for(i=0;i<N;i++)
    {
        scanf("%d",&num);
        if(num!=0)
        {
            stack[l++] = num;
        }
        else
        {
            stack[--l] = 0;
        }
    }
    
    for(i=0;i<l;i++)
        answer += stack[i];
    
    printf("%d",answer);
    
    return 0;
}