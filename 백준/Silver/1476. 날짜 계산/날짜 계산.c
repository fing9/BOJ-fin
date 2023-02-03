# include <stdio.h>

int main()
{
    int E, S, M;
    int a=0, b=0, c=0;
    int i;
    scanf("%d %d %d",&E,&S,&M);
    for(i=1;i<=7980;i++)
    {
        a++;
        b++;
        c++;
        if(a>15)
            a=1;
        if(b>28)
            b=1;
        if(c>19)
            c=1;
        if(a==E && b==S && c==M)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}