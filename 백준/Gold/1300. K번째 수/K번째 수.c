# include <stdio.h>
int N, k;

int min(int x, int y)
{
    if(x>=y)
        return y;
    else
        return x;
}

void BinarySearch()
{
    int first = 1;
    int last = k;
    int mid = 1;
    int ret;
    while(first <= last)
    {
        int cnt = 0;
        mid = (first+last) / 2;
        for(int i=1;i<=N;i++)
            cnt += min(mid/i,N);
        if(cnt < k)
            first = mid + 1;
        else
        {
            ret = mid;
            last = mid - 1;
        }
    }
    
    printf("%d",ret);
    return;
}

int main()
{
    scanf("%d",&N);
    scanf("%d",&k);
    
    BinarySearch();
    
    return 0;
}