#include <iostream>
using namespace std;
int map[103][103];
int N, ret_g=0, ret_s=0;

int main()
{
    for(int i=0;i<103;i++) // 맵 초기화
    {
        for(int j=0;j<103;j++)
        {
            map[i][j] = 1; // 1은 벽or막힌곳, 0은 누울 수 있는 곳
        }
    }
    
    scanf("%d",&N); // 입력부
    for(int i=0;i<N;i++)
    {
        char inp[103];
        scanf("%s",inp);
        for(int j=0;j<N;j++)
        {
            if(inp[j]=='.')
            {
                map[i][j]=0;
            }
        }
    }
    
    // 가로로 누울 수 있는 갯수 체크
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j]==0 && map[i][j+1]==0)
            {
                ret_g++;
                int l=j;
                while(map[i][l]==0)
                {
                    map[i][l++]=2;
                }
            }
        }
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j]==2) map[i][j]=0;
        }
    }
    
    // 세로로 누울 수 있는 갯수 체크
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[j][i]==0 && map[j+1][i]==0)
            {
                ret_s++;
                int l=j;
                while(map[l][i]==0)
                {
                    map[l++][i]=2;
                }
            }
        }
    }
    
    printf("%d %d",ret_g,ret_s);
    return 0;
}