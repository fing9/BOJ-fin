# include <stdio.h>
# define SIZE 100001
int sorted_head[SIZE];
int sorted_tail[SIZE];


void merge(int list_head[],int list_tail[],int left,int mid,int right)
{
    int i, j, k, l;
    //i는 left의 index
    //j는 right의 index
    //k는 sorted의 index
    i=left;
    j=mid+1;
    k=left;
    
    while(i<=mid && j<=right)
    {
        if(list_head[i]<list_head[j])
        {
            sorted_head[k] = list_head[i];
            sorted_tail[k++] = list_tail[i++];
        }
        else if(list_head[i]>list_head[j])
        {
            sorted_head[k] = list_head[j];
            sorted_tail[k++] = list_tail[j++];
        }
        else
        {
            if(list_tail[i]<list_tail[j])
            {
                sorted_head[k] = list_head[i];
                sorted_tail[k++] = list_tail[i++];
            }
            else
            {
                sorted_head[k] = list_head[j];
                sorted_tail[k++] = list_tail[j++];
            }
        }
    }
    if(i>mid)
    {
        for(l=j;l<=right;l++)
        {
            sorted_head[k] = list_head[l];
            sorted_tail[k++] = list_tail[l];
        }
    }
    else
    {
        for(l=i;l<=mid;l++)
        {
            sorted_head[k] = list_head[l];
            sorted_tail[k++] = list_tail[l];
        }
    }
    
    for(l=left;l<=right;l++)
    {
        list_head[l] = sorted_head[l];
        list_tail[l] = sorted_tail[l];
    }
}


void merge_sort(int list_head[],int list_tail[],int left,int right)
{
    int mid;
    mid = (left+right)/2;
    if(left!=right)
    {
        merge_sort(list_head,list_tail,left,mid);
        merge_sort(list_head,list_tail,mid+1,right);
        merge(list_head,list_tail,left,mid,right);
    }
}


int main()
{
    int N;
    scanf("%d",&N);
    int DP[N], Max=0, answer=0, line_L[N], line_R[N], i, j;
    for(i=0;i<N;i++)
        scanf("%d %d",&line_L[i],&line_R[i]);
    
    merge_sort(line_L,line_R,0,N-1);
    
    for(i=0;i<N;i++)
    {
        DP[i] = 1;
    }
    
        for(i=N-2;i>=0;i--)
        {
            for(j=i+1;j<N;j++)
            {
                if(line_R[i]<line_R[j] && DP[j]>Max)
                {
                    Max = DP[j];
                }
            }
            DP[i] = Max + 1;
            Max = 0;
        }
    
    for(i=0;i<N;i++)
    {
        if(DP[i]>answer)
            answer = DP[i];
    }
    
    printf("%d",N-answer);
    
    return 0;
}