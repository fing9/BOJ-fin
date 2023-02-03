# include <stdio.h>

int main()
{
    long long wood[1000000]={0,}, bottom=0, top=0, C, cuted=0;
    int N, M;
    int i;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)
    {
        scanf("%lld",&wood[i]);
        if(wood[i]>top)
            top=wood[i];
    }
    
    while(bottom<=top)
    {
        long long mid;
        mid=(bottom+top)/2;
        cuted=0;
        for(i=0;i<N;i++)
        {
            if(wood[i]>mid)
                cuted+=wood[i]-mid;
        }
        
        if(cuted>=M)
        {
            bottom=mid+1;
        }
        else
        {
            top=mid-1;
        }
    }
    
    printf("%lld",bottom-1);
    
    return 0;
}