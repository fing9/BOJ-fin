# include <stdio.h>
# define SIZE 6562
char arr[SIZE][SIZE];

void star(int N,int x, int y)
{
    int i, j;
    
    if(N==1)
    {
        arr[x][y] = '*';
        return;
    }
    
    N/=3;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i==1 && j==1)
                continue;
            star(N,x+(i*N),y+(j*N));
        }
    }
}

int main()
{
    int N, i, j;
    scanf("%d",&N);
    star(N,0,0);
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(arr[i][j] == NULL)
                printf(" ");
            else
                printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}