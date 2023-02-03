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
    int N, i, j;
    int sum=0, modint=0;
    int most[8001]={0,}, max=0, max2=0, maxn=0, maxn2=0;
    double mod=0, cp=0;
    scanf("%d",&N);
    int num[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
        sum+=num[i];
        most[4000+num[i]]+=1;
    }
    
    qsort(num, sizeof(num)/sizeof(int), sizeof(int), compare);
    
    modint = sum/N;
    mod = ((double)sum/(double)N);
    if(mod>=0)
    {
        cp = mod-(double)modint;
        if(cp>=0.5)
            cp=1;
        else
            cp=0;
        
        modint += cp;
    }
    else
    {
        cp = mod-(double)modint;
        if(cp<=-0.5)
            cp=-1;
        else
            cp=0;
        
        modint += cp;
    }
    
    printf("%d\n",modint);
    
    printf("%d\n",num[(N-1)/2]);
    
    for(i=8000;i>=0;i--)
    {
        if(most[i]>max)
        {
            max=most[i];
            maxn=i-4000;
        }
        else if(most[i]==max)
        {
            max2=max;
            maxn2=maxn;
            max=most[i];
            maxn=i-4000;
        }
    }
    
    if(max==max2)
        printf("%d\n",maxn2);
    else
        printf("%d\n",maxn);
    
    printf("%d",num[N-1]-num[0]);
    
    return 0;
}