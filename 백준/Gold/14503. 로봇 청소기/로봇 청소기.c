# include <stdio.h>
# include <string.h>
int map[53][53], cheak[53][53];
int N, M, turn=0, count=0, run=1;

int main()
{
    int r, c, d;
    int i, j;
    
    for(i=0;i<=53;i++) // reset
    {
        memset(map[i],1,sizeof(map[i]));
        memset(cheak[i],0,sizeof(cheak[i]));
    }
    
    scanf("%d %d",&N,&M); // input
    scanf("%d %d %d",&r,&c,&d);
    for(i=N-1;i>=0;i--)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    
    r=N-1-r;
    cheak[r][c]=1;
    
    while(run==1)
    {
        if(d==0) // 북
        {
            if(turn==4 && map[r-1][c]!=1) // c
            {
                r-=1;
                turn=0;
            }
            else if(turn==4 && map[r-1][c]==1) // d
            {
                run=0;
            }
            else if(map[r][c-1]==0 && cheak[r][c-1]==0) // a
            {
                d=3;
                c-=1;
                cheak[r][c]=1;
                turn=0;
            }
            else if(cheak[r][c-1]!=0 || (map[r][c-1]==1 && cheak[r][c-1]==0)) // b
            {
                d=3;
                turn+=1;
            }
        }
        else if(d==1) // 동
        {
            if(turn==4 && map[r][c-1]!=1) // c
            {
                c-=1;
                turn=0;
            }
            else if(turn==4 && map[r][c-1]==1) // d
            {
                run=0;
            }
            else if(map[r+1][c]==0 && cheak[r+1][c]==0) // a
            {
                d=0;
                r+=1;
                cheak[r][c]=1;
                turn=0;
            }
            else if(cheak[r+1][c]!=0 || (map[r+1][c]==1 && cheak[r+1][c]==0)) // b
            {
                d=0;
                turn+=1;
            }
        }
        else if(d==2) // 남
        {
            if(turn==4 && map[r+1][c]!=1) // c
            {
                r+=1;
                turn=0;
            }
            else if(turn==4 && map[r+1][c]==1) // d
            {
                run=0;
            }
            else if(map[r][c+1]==0 && cheak[r][c+1]==0) // a
            {
                d=1;
                c+=1;
                cheak[r][c]=1;
                turn=0;
            }
            else if(cheak[r][c+1]!=0 || (map[r][c+1]==1 && cheak[r][c+1]==0)) // b
            {
                d=1;
                turn+=1;
            }
        }
        else if(d==3) // 서
        {
            if(turn==4 && map[r][c+1]!=1) // c
            {
                c+=1;
                turn=0;
            }
            else if(turn==4 && map[r][c+1]==1) // d
            {
                run=0;
            }
            else if(map[r-1][c]==0 && cheak[r-1][c]==0) // a
            {
                d=2;
                r-=1;
                cheak[r][c]=1;
                turn=0;
            }
            else if(cheak[r-1][c]!=0 || (map[r-1][c]==1 && cheak[r-1][c]==0)) // b
            {
                d=2;
                turn+=1;
            }
        }
    }
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if(map[i][j]==0 && cheak[i][j]==1)
                count+=1;
        }
    }
    
    printf("%d",count);
    
    return 0;
}