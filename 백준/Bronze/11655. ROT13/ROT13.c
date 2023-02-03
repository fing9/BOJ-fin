# include <stdio.h>
# include <string.h>

int main()
{
    int n, tmp, i;
    char s[102], answer[102];
    
    gets(s);
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        tmp=s[i];
        if(tmp==' ' || (48<=tmp && tmp<=57))
        {
            answer[i]=tmp;
        }
        else
        {
            if(65<=tmp && tmp<=90)
            {
                tmp+=13;
                if(tmp>=91)
                    tmp-=26;
            }
            else if(97<=tmp && tmp<=122)
            {
                tmp+=13;
                if(tmp>=123)
                    tmp-=26;
            }
            answer[i]=tmp;
        }
        printf("%c",answer[i]);
    }
    return 0;
}