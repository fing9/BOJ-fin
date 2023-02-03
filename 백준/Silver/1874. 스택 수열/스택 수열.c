# include <stdio.h>
int n, num[200000]={0,}, answer[400000]={0,};
int stack[200002], l=1, k=0;

void solve()
{
    int i=0, m;
    for(m=1;m<=n;m++)
    {
        while(stack[l-1]==num[i])
        {
            answer[k++]=1; //1이 pop
            i++;
            if(l>1)
                l--;
        }
        
        answer[k++]=2; //2가 push
        stack[l++]=m;
    }
    while(stack[l-1]==num[i])
    {
        answer[k++]=1; //1이 pop
        i++;
        if(l>1)
            l--;
    }
}

int main()
{
    int i;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    
    solve();
    
    if(l==1)
    {
        for(i=0;i<n*2;i++)
        {
            if(answer[i]==1)
            {
                printf("-");
            }
            else if(answer[i]==2)
            {
                printf("+");
            }
            if(i!=(n*2)-1)
                printf("\n");
        }
    }
    else
    {
        printf("NO");
    }
    
    return 0;
}