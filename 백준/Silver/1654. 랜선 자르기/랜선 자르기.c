#include <string.h>
 
int K = 0; // 오영식이 이미 가지고 있는 랜선의 개수
int N = 0; // 필요한 랜선의 개수
 
long long lan[10001] = { 0, };
 
long long binarySearch(long long left, long long right)
{
    while (left <= right)
    {
        int Cnt = 0;
 
        long long middle = (left + right) / 2;
 
        for (int i = 0; i <= K; i++)
        {
            Cnt += lan[i] / middle;
        }
 
        // 내가 찾은 개수(Cnt)가 N보다 더 크다면, 더 큰 수로 나눠야 하니 left를 증가시킨다.
        if (Cnt >= N) left = middle + 1;
        else right = middle - 1;
    }
 
    return right;
}
 
int main(void)
{
    long long max = 0;
     
    scanf("%d %d", &K, &N);
 
    for(int i=0; i<K; i++)
    {
        scanf("%lld", &lan[i]);
 
        if (max < lan[i]) max = lan[i];
    }
 
    printf("%lld\n", binarySearch(1, max));
 
    return 0;
}