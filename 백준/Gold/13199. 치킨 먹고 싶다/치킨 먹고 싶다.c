# include <stdio.h>

int main()
{
    int T, P, M, F, C, answer1=0, answer2=0, i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        answer1=0;
        answer2=0;
        scanf("%d %d %d %d",&P,&M,&F,&C);
        
        answer1 = (M/P);
        answer2 = (M/P);
        if((((M/P)*C)-F) > 0)
        {
            answer1 += ((((M/P)*C)-F)/(F-C))+1;
        }
        else
        {
            answer1 += (((M/P)*C)/F);
        }
        answer2 += (((M/P)*C)/F);
        printf("%d\n",answer1-answer2);
    }
    return 0;
}