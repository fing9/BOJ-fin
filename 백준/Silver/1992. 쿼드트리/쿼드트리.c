# include <stdio.h>
# include <stdio.h>
int N, head=0, tail=0;
char map[1000][1000], queue[2000000];

void solve(int A, int B, int d)
{
    int mid, i, j;
    int cb=0, cw=0;
    
    if(d==1)
    {
        if(map[A][B]=='1')
        {
            queue[tail++]='1';
            return;
        }
        else
        {
            queue[tail++]='0';
            return;
        }
    }
    else
    {
        queue[tail++]='(';
        mid=d/2;
        for(i=A;i<A+mid;i++) // 1
        {
            for(j=B;j<B+mid;j++)
            {
                if(map[i][j]=='1')
                {
                    cb++;
                }
                else
                {
                    cw++;
                }
            }
        }
        if(cb==0)
        {
            queue[tail++]='0';
        }
        else if(cw==0)
        {
            queue[tail++]='1';
        }
        else
        {
            solve(A,B,mid);
        }
        cb=0;
        cw=0;
        
        for(i=A;i<A+mid;i++) // 2
        {
            for(j=B+mid;j<B+mid+mid;j++)
            {
                if(map[i][j]=='1')
                {
                    cb++;
                }
                else
                {
                    cw++;
                }
            }
        }
        if(cb==0)
        {
            queue[tail++]='0';
        }
        else if(cw==0)
        {
            queue[tail++]='1';
        }
        else
        {
            solve(A,B+mid,mid);
        }
        cb=0;
        cw=0;
        
        for(i=A+mid;i<A+mid+mid;i++) // 3
        {
            for(j=B;j<B+mid;j++)
            {
                if(map[i][j]=='1')
                {
                    cb++;
                }
                else
                {
                    cw++;
                }
            }
        }
        if(cb==0)
        {
            queue[tail++]='0';
        }
        else if(cw==0)
        {
            queue[tail++]='1';
        }
        else
        {
            solve(A+mid,B,mid);
        }
        cb=0;
        cw=0;
        
        for(i=A+mid;i<A+mid+mid;i++) // 4
        {
            for(j=B+mid;j<B+mid+mid;j++)
            {
                if(map[i][j]=='1')
                {
                    cb++;
                }
                else
                {
                    cw++;
                }
            }
        }
        if(cb==0)
        {
            queue[tail++]='0';
        }
        else if(cw==0)
        {
            queue[tail++]='1';
        }
        else
        {
            solve(A+mid,B+mid,mid);
        }
        cb=0;
        cw=0;
        queue[tail++]=')';
    }
    
}

int main()
{
    int black=0, white=0;
    int i, j;
    scanf("%d",&N);
    for(i=0;i<1000;i++)
        memset(map[i],NULL,sizeof(map[i]));
    memset(queue,NULL,sizeof(queue));
    
    for(i=0;i<N;i++)
    {
        scanf("%s",&map[i][0]);
    }
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(map[i][j]=='0')
                white++;
            else
                black++;
        }
    }
    if(white==0)
        queue[tail++]='1';
    else if(black==0)
        queue[tail++]='0';
    else
        solve(0,0,N);
    
    printf("%s",queue);
    
    return 0;
}