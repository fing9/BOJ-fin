# include <stdio.h>
# define SIZE 100001
int sorted[SIZE];
int sorted_tail[SIZE];

void merge(int list[],int list_tail[],int left,int mid,int right)
{
    int i,j,l,k;
    i=left;
    j=mid+1;
    l=left;
    
    while(i<=mid && j<=right) //요소 크기비교
    {
        if(list[i]<list[j])
        {
            sorted[l] = list[i];
            sorted_tail[l] = list_tail[i];
            l++;
            i++;
        }
        else if(list[i]>list[j])
        {
            sorted[l] = list[j];
            sorted_tail[l] = list_tail[j];
            l++;
            j++;
        }
        else
        {
            if(list_tail[i]<=list_tail[j])
            {
                sorted[l] = list[i];
                sorted_tail[l] = list_tail[i];
                l++;
                i++;
            }
            else
            {
                sorted[l] = list[j];
                sorted_tail[l] = list_tail[j];
                l++;
                j++;
            }
        }
    }
    
    if(i>mid) //남아있는 값들 일괄적으로 넣기
    {
        for(k=j;k<=right;k++)
        {
            sorted[l] = list[k];
            sorted_tail[l] = list_tail[k];
            l++;
        }
    }
    else
    {
        for(k=i;k<=mid;k++)
        {
            sorted[l] = list[k];
            sorted_tail[l] = list_tail[k];
            l++;
        }
    }
    
    for(k=left;k<=right;k++) //다시넣기
    {
        list[k] = sorted[k];
        list_tail[k] = sorted_tail[k];
    }
}
    
void mergesort(int list[],int list_tail[],int left, int right)
{
    int mid;
    
    if(left<right)
    {
        mid = (left+right)/2;
        mergesort(list,list_tail,left,mid);
        mergesort(list,list_tail,mid+1,right);
        merge(list,list_tail,left,mid,right);
    }
}

int main()
{
    int N, i, j, k=0, answer=1;
    scanf("%d",&N);
    int list_start[N];
    int list_end[N];
    
    for(i=0;i<N;i++)
        scanf("%d %d",&list_start[i],&list_end[i]);
    
    mergesort(list_end,list_start,0,N-1);
    
    for(i=1;i<N;i++)
    {
        if(list_end[k]<=list_start[i])
        {
            answer++; //회의 수 추가
            k=i;
        }
    }
    
    printf("%d",answer);
    
    return 0;
}