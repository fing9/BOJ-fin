# include <stdio.h>
# include <string.h>

int main()
{
    int answer=0;
    int N, now=0, i;
    char arr[100005];
    
    scanf("%s",arr);
    N=strlen(arr);
    
    for(i=0;i<N;i++)
    {
        if(arr[i]=='(')
            now++;
        else if(arr[i]==')' && arr[i-1]=='(')
        {
            now--;
            answer+=now;
        }
        else
        {
            now--;
            answer++;
        }
    }
    
    printf("%d",answer);
    
    return 0;
}