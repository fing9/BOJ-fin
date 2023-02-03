# include <stdio.h>
# include <string.h>

int main()
{
    char str[51], trans_char[7];
    int n, i, j, tail=0, l=0;
    int answer=0, sum=0, transed_int=0, is_minus=0;
    scanf("%s",str);
    n=strlen(str);
    
    for(i=0;i<6;i++)
    {
        if(str[tail]!='-' && str[tail]!='+')
        {
            trans_char[l++] = str[tail++];
            if(i==n-1)
            {
                transed_int = atoi(trans_char);
                answer += transed_int;
            }
        }
        else
        {
            if(str[tail]=='-')
            {
                is_minus=1;
            }
            transed_int = atoi(trans_char);
            answer += transed_int;
            for(j=0;j<7;j++)
                trans_char[j] = '\0';
            l=0;
            i=7;
            tail++;
        }
    }
    
    for(i=tail;i<n;i++)
    {
        if(str[i]!='-' && str[i]!='+')
        {
            trans_char[l] = str[i];
            l++;
            if(i==n-1 && is_minus==1)
            {
                transed_int = atoi(trans_char);
                answer -= sum+transed_int;
            }
            else if(i==n-1 && is_minus==0)
            {
                transed_int = atoi(trans_char);
                answer += sum+transed_int;
            }
        }
        else if(str[i]=='-' && is_minus==1)
        {
            transed_int = atoi(trans_char);
            answer -= sum+transed_int;
            sum=0;
            for(j=0;j<7;j++)
                trans_char[j] = '\0';
            l=0;
        }
        else if(str[i]=='-' && is_minus==0)
        {
            transed_int = atoi(trans_char);
            answer += sum+transed_int;
            sum=0;
            for(j=0;j<7;j++)
                trans_char[j] = '\0';
            l=0;
            is_minus=1;
        }
        else if(str[i]=='+')
        {
            transed_int = atoi(trans_char);
            sum += transed_int;
            for(j=0;j<7;j++)
                trans_char[j] = '\0';
            l=0;
        }
    }
    
    printf("%d",answer);
    return 0;
}