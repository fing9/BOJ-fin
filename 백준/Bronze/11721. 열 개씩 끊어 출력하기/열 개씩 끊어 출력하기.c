# include <stdio.h>

int main()
{
    char out, count=0;
    while(scanf("%c",&out)!=-1)
    {
        if(count<10)
            printf("%c",out);
        else
        {
            count=0;
            printf("\n");
            printf("%c",out);
        }
        count++;
    }
   return 0;
}