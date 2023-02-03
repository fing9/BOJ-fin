# include <stdio.h>
# include <string.h>

int main()
{
    int l, i, j, judge = 1;
    char num[102], stack[102];
    
    while(1)
    {
        j = 1;
        l = 1;
        judge = 1;
        memset(num,NULL,sizeof(num));
        memset(stack,NULL,sizeof(stack));
        
        gets(num);
        if(num[0]=='.')
        {
            return 0;
        }
        
        for(j=0;num[j]!='.';j++)
        {
            if(num[j]=='(')
            {
                stack[l++] = '(';
            }
            else if(num[j]==')' && l>1)
            {
                if(stack[l-1]=='[')
                {
                    printf("no\n");
                    judge = 0;
                    l = 10;
                    break;
                }
                stack[--l] = NULL;
            }
            else if(num[j]==')' && l==1)
            {
                printf("no\n");
                judge = 0;
                l = 10;
                break;
            }
            
            if(num[j]=='[')
            {
                stack[l++] = '[';
            }
            else if(num[j]==']' && l>1)
            {
                if(stack[l-1]=='(')
                {
                    printf("no\n");
                    judge = 0;
                    l = 10;
                    break;
                }
                stack[--l] = NULL;
            }
            else if(num[j]==']' && l==1)
            {
                printf("no\n");
                judge = 0;
                l = 10;
                break;
            }
        }
        
        
        
        if(l==1)
        {
            printf("yes\n");
        }
        else if(judge==1)
        {
            printf("no\n");
        }
    }
    
    return 0;
}