# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int map[500001], l=0;
int N, M;

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int Search(int x, int left, int right)
{
    int mid;
    mid = (left+right)/2;
    if(map[left]==x && left==right)
        return 1;
    else if(left!=right && left<right)
        return Search(x,left,mid) + Search(x,mid+1,right);
    
    return 0;
}

int Lower_Bound(int x, int left, int right)
{
    int mid;
    
    while(left < right)
    {
        mid = (left+right)/2;
        if(map[mid] >= x)
            right = mid;
        else
            left = mid+1;
    }
    
    return right;
}

int Upper_Bound(int x, int left, int right)
{
    int mid;
    
    while(left < right)
    {
        mid = (left+right)/2;
        if(map[mid] > x)
            right = mid;
        else
            left = mid+1;
    }
    
    return right;
}

int main()
{
    int a, i, j;
    
    memset(map,0,sizeof(map));
    
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&a);
        map[l++]=a;
    }
    
    qsort(map, sizeof(map)/sizeof(int), sizeof(int), compare);
    
    scanf("%d",&M);
    for(i=0;i<M;i++)
    {
        scanf("%d",&a);
        if(a!=0)
            printf("%d",Upper_Bound(a,0,500001) - Lower_Bound(a,0,500001));
        else
        {
            printf("%d",N - (500000 - Upper_Bound(a,0,500001) + Lower_Bound(a,0,500001))-1);
        }
        if(i!=M-1)
            printf(" ");
    }
    
    return 0;
}