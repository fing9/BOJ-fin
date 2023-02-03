# include <stdio.h>
int map[3000][3000], N;
int rs1=0, rs2=0, rs3=0;
int c1=0, c2=0, c3=0;

void solve(int A, int B, int d) // A는 아래 B는 오른쪽
{
    int mid, i, j;
    
    if(d==1)
    {
        if(map[A][B]==-1)
        {
            rs1++;
            return;
        }
        else if(map[A][B]==0)
        {
            rs2++;
            return;
        }
        else
        {
            rs3++;
            return;
        }
    }
    else
    {
        mid=d/3;
        c1=0;
        c2=0;
        c3=0;
        for(i=A;i<A+mid;i++) // 1
        {
            for(j=B;j<B+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A,B,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A;i<A+mid;i++) // 2
        {
            for(j=B+mid;j<B+mid+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A,B+mid,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A;i<A+mid;i++) // 3
        {
            for(j=B+mid+mid;j<B+mid+mid+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A,B+mid+mid,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A+mid;i<A+mid+mid;i++) // 4
        {
            for(j=B;j<B+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A+mid,B,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A+mid;i<A+mid+mid;i++) // 5
        {
            for(j=B+mid;j<B+mid+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A+mid,B+mid,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A+mid;i<A+mid+mid;i++) // 6
        {
            for(j=B+mid+mid;j<B+mid+mid+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A+mid,B+mid+mid,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A+mid+mid;i<A+mid+mid+mid;i++) // 7
        {
            for(j=B;j<B+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A+mid+mid,B,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A+mid+mid;i<A+mid+mid+mid;i++) // 8
        {
            for(j=B+mid;j<B+mid+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A+mid+mid,B+mid,mid);
        
        c1=0;
        c2=0;
        c3=0;
        for(i=A+mid+mid;i<A+mid+mid+mid;i++) // 9
        {
            for(j=B+mid+mid;j<B+mid+mid+mid;j++)
            {
                if(map[i][j]==-1)
                    c1++;
                else if(map[i][j]==0)
                    c2++;
                else
                    c3++;
            }
        }
        if(c2==0 && c3==0)
            rs1++;
        else if(c1==0 && c3==0)
            rs2++;
        else if(c1==0 && c2==0)
            rs3++;
        else
            solve(A+mid+mid,B+mid+mid,mid);
        
    }
}

int main()
{
    int i, j;
    int ck1=0, ck2=0, ck3=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]==-1)
                ck1++;
            else if(map[i][j]==0)
                ck2++;
            else
                ck3++;
        }
    }
    
    if(ck2==0 && ck3==0)
        printf("1\n0\n0");
    else if(ck1==0 && ck3==0)
        printf("0\n1\n0");
    else if(ck1==0 && ck2==0)
        printf("0\n0\n1");
    else
    {
        solve(0,0,N);
        printf("%d\n%d\n%d",rs1,rs2,rs3);
    }
    
    return 0;
}