#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N=0, num;
    for(int i=0;i<3;i++)
    {
        N=0;
        for(int j=0;j<4;j++)
        {
            scanf("%d",&num);
            if(num==0)
                N++;
        }
        if(N==0)
            printf("E");
        else if(N==1)
            printf("A");
        else if(N==2)
            printf("B");
        else if(N==3)
            printf("C");
        else
            printf("D");
        if(i!=2)
            printf("\n");
    }
    return 0;
}