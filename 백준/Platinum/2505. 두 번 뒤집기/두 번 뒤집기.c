# include <stdio.h>
# include <string.h>

int board[10001];
int board_back[10001];
int answer[10001][2];
int true_answer[2][2];
int l=0;

void solve(int N)
{
    int i, j, tmp;
    
    //l은 answer의 index
    
    for(i=1;i<=N;i++)
    {
        if(board[i] != i)
        {
            for(j=i+1;j<=N;j++)// 답찾기
            {
                if(board[j] == i)
                {
                    answer[l][0] = i;
                    answer[l][1] = j;
                    j=N+1;
                }
            }
            for(j=0;j<=(answer[l][1]-answer[l][0])/2;j++) //거꾸로 뒤집기
            {
                tmp = board[answer[l][1]-j];
                board[answer[l][1]-j] = board[answer[l][0]+j];
                board[answer[l][0]+j] = tmp;
            }
            l++;
        }
    }
}

void solve_back(int N)
{
    int i, j, tmp;
    
    l=0;
    //l은 answer의 index
    
    for(i=N;i>0;i--)
    {
        if(board_back[i] != i)
        {
            for(j=i-1;j>0;j--)// 답찾기
            {
                if(board_back[j] == i)
                {
                    answer[l][0] = j;
                    answer[l][1] = i;
                    j=0;
                }
            }
            for(j=0;j<=(answer[l][1]-answer[l][0])/2;j++) //거꾸로 뒤집기
            {
                tmp = board_back[answer[l][1]-j];
                board_back[answer[l][1]-j] = board_back[answer[l][0]+j];
                board_back[answer[l][0]+j] = tmp;
            }
            l++;
        }
    }
}

int main()
{
    int n, i, j, is_print=0;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&board[i]);
        board_back[i] = board[i];
    }
    
    solve(n);
    if(l>2)
        solve_back(n);
    
    if(l<=2)
    {
        if(answer[0][0]==0)
            is_print++;
        else
            printf("%d %d\n",answer[0][0],answer[0][1]);
        
        if(answer[1][0]==0)
            is_print++;
        else
            printf("%d %d\n",answer[1][0],answer[1][1]);
        if(is_print==1)
        {
            printf("1 1");
        }
        else if(is_print==2)
        {
            printf("1 1\n");
            printf("1 1");
        }
    }
    else
    {
        if(true_answer[0][0]==0)
            is_print++;
        else
            printf("%d %d\n",true_answer[0][0],true_answer[0][1]);
        
        if(true_answer[1][0]==0)
            is_print++;
        else
            printf("%d %d\n",true_answer[1][0],true_answer[1][1]);
        if(is_print==1)
        {
            printf("1 1");
        }
        else if(is_print==2)
        {
            printf("1 1\n");
            printf("1 1");
        }
    }
    
    return 0;
}