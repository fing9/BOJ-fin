#include <iostream>

using namespace std;

int main()
{
    int arr[4] = {0,};
    int M, tmp;
    scanf("%d", &M);
    arr[1] = 1;
    
    while(M--)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        
        tmp = arr[from];
        arr[from] = arr[to];
        arr[to] = tmp;
    }
    
    for(int i=1;i<=3;i++)
    {
        if(arr[i] == 1)
            printf("%d", i);
    }
    
    return 0;
}