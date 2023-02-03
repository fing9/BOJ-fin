#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++)
    {
        if(i%2==1)
        {
            printf("*");
            for(int l=1;l<N;l++)
                printf(" *");
        }
        else
        {
            printf(" *");
            for(int l=1;l<N;l++)
                printf(" *");
        }
        if(i!=N)
            printf("\n");
    }
    
    return 0;
}