# include <stdio.h>
# include <string.h>

int main()
{
    int l, N, i, j, judge = 1;
    char num[51];
    scanf("%d",&N);
    
    for(i=0;i<N;i++)
    {
        l = 0;
        judge = 1;
        memset(num,NULL,sizeof(num));
        scanf("%s",num);
        for(j=0;num[j]!=NULL;j++)
        {
            if(num[j]=='(')
            {
                l++;
            }
            else if(num[j]==')' && l>0)
            {
                l--;
            }
            else
            {
                printf("NO\n");
                judge = 0;
                l = 10;
                break;
            }
        }
        if(l==0)
        {
            printf("YES\n");
        }
        else if(judge == 1)
        {
            printf("NO\n");
        }
    }
    
    return 0;
}