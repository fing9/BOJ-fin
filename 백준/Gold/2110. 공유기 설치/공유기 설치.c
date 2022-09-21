# include <stdio.h>
# include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main()
{
    int N, C;
    int i;
    scanf("%d %d",&N,&C);
    int num[N];
    
    for(i=0;i<N;i++)
        scanf("%d",&num[i]);
    
    qsort(num,sizeof(num)/sizeof(int),sizeof(int),compare);
    
    int left=1, right, mid, start, cnt;
    int d = 0;
    int ans = 0;
    right=num[N-1]-num[0];
    
    while(left<=right)
    {
        mid = (left+right) / 2;
        start = num[0];
        cnt = 1;
        
        for(i=1;i<N;i++)
        {
            d=num[i]-start;
            if(mid<=d)
            {
                ++cnt;
                start=num[i];
            }
        }
        
        if(cnt>=C)
        {
            ans=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}