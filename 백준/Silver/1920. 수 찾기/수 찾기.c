# include <stdio.h>
# include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

void binary_search(int list[],int Num,int low,int max)
{
    int mid;
    mid = (low+max)/2;
    if(Num == list[mid])
    {
        printf("1\n");
        return;
    }
    else if(Num<list[mid] && low!=max)
    {
        binary_search(list,Num,low,mid);
    }
    else if(Num>list[mid] && low!=max)
    {
        binary_search(list,Num,mid+1,max);
    }
    else
    {
        printf("0\n");
        return;
    }
}

int main()
{
    int N, M, Num, i;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);
    
    qsort(arr,sizeof(arr)/sizeof(int),sizeof(int), compare);
    
    scanf("%d",&M);
    for(i=0;i<M;i++)
    {
        scanf("%d",&Num);
        binary_search(arr,Num,0,N-1);
    }
    
    return 0;
}