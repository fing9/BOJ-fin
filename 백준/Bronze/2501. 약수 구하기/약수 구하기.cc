#include <iostream>

using namespace std;

int main()
{
    int N, K, cnt = 0;
    scanf("%d %d", &N, &K);
    
    for(int i = 1;i <= N;i++)
    {
        if(N % i == 0) {
            cnt++;
        }
        if(cnt == K) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
    
    return 0;
}