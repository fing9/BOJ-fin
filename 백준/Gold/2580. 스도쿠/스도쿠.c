# include <stdio.h>
int map[9][9];
int stack[1000000][2], head=0, tail=0;

int cheak(int y, int x, int num)
{
    int i, j;
    
    for(i=0;i<9;i++)
    {
        if(map[y][i]==num)
        {
            return 0;
        }
        if(map[i][x]==num)
        {
            return 0;
        }
    }
    
    if(y<3 && x<3) // 1
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<3 && x<6) // 2
    {
        for(i=0;i<3;i++)
        {
            for(j=3;j<6;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<3 && x<9) // 3
    {
        for(i=0;i<3;i++)
        {
            for(j=6;j<9;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<6 && x<3) // 4
    {
        for(i=3;i<6;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<6 && x<6) // 5
    {
        for(i=3;i<6;i++)
        {
            for(j=3;j<6;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<6 && x<9) // 6
    {
        for(i=3;i<6;i++)
        {
            for(j=6;j<9;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<9 && x<3) // 7
    {
        for(i=6;i<9;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<9 && x<6) // 8
    {
        for(i=6;i<9;i++)
        {
            for(j=3;j<6;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    else if(y<9 && x<9) // 9
    {
        for(i=6;i<9;i++)
        {
            for(j=6;j<9;j++)
            {
                if(i!=y && j!=x)
                {
                    if(map[i][j]==num)
                        {
                            return 0;
                        }
                }
            }
        }
    }
    
    return 1;
}

void solve()
{
    int i, j, k;
    
    if(head>=tail)
    {
        return;
    }
    else
    {
        i=stack[head][0];
        j=stack[head++][1];
        map[i][j]=0;
        for(k=1;k<10;k++)
        {
            if(cheak(i,j,k)==1)
            {
                map[i][j]=k;
                solve();
                if(head>=tail)
                {
                    return;
                }
                map[i][j]=0;
            }
        }
        if(map[i][j]==0)
        {
            head--;
            return;
        }
    }
}

int main()
{
    int i, j, k;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==0)
            {
                stack[tail][0]=i;
                stack[tail++][1]=j;
            }
        }
    }
    
    solve();
    
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}