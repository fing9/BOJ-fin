# include <stdio.h>
# include <string.h>

int main()
{
    int a, b, c, d, i;
    char arr[102];
    
    while(gets(arr))
    {
        a=0;
        b=0;
        c=0;
        d=0;
        
        for(i=0;i<strlen(arr);i++)
        {
            if(97<=arr[i] && arr[i]<=122)
                a++;
            else if(65<=arr[i] && arr[i]<=90)
                b++;
            else if(48<=arr[i] && arr[i]<=57)
                c++;
            else if(arr[i]==' ')
                d++;
        }
        
        printf("%d %d %d %d\n",a,b,c,d);
    }
    
    return 0;
}