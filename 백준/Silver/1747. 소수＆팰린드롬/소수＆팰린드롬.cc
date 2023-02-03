#include <iostream>
using namespace std;

int main()
{
    int N, a[1004000];
    scanf("%d",&N);
    
    //에라토스테네스의 체로 거르기
    for(int i=0;i<1004000;i++)
    {
        a[i]=i;
    }
    for(int i=2;i<1004000;i++)
    {
        if(a[i]==0) continue;
        for(int j=i+i;j<1004000;j+=i)
        {
            a[j]=0;
        }
    }
    
    //모든 빈공간에 숫자 집어넣기
    int tmp=1003001, d;
    for(int i=1003999;i>0;i--)
    {
        if(a[i]!=0)
        {
            int len=0;
            int b[10], c[10];
            bool isprd=true;
            for(int j=0;j<10;j++) // b,c 초기화
            {
                b[j]=-1;
                c[j]=-1;
            }
            d=a[i];
            while(d>0)
            {
                d/=10;
                len++;
            }
            d=a[i];
            for(int j=0;j<len;j++)
            {
                b[j]=d%10;
                d/=10;
            }
            int l=len-1;
            for(int j=0;j<len;j++)
            {
                c[j]=b[l--];
            }
            
            for(int j=0;j<(len/2);j++)
            {
                if(b[j]!=c[j])
                {
                    isprd=false;
                }
            }
            
            if(isprd)
            {
                tmp=a[i];
            }
            else
            {
                a[i]=tmp;
            }
        }
        else
        {
            a[i]=tmp;
        }
    }
    
    a[1]=2;
    printf("%d",a[N]);
    
    return 0;
}