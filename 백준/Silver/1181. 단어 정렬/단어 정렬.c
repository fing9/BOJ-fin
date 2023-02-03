# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int compare1(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int compare2(const void *first, const void *second)
{
    if(strlen((char *)first) < strlen((char *)second))
        return -1;
    if(strlen((char *)first) > strlen((char *)second))
        return 1;
    
    return 0;
}

int main()
{
    int N, i, j;
    scanf("%d",&N);
    char words[N][51], last[51];
    for(i=0;i<N;i++)
        scanf("%s",&words[i][0]);
    
    qsort(words,sizeof(words)/sizeof(words[0]),sizeof(words[0]),compare1);
    qsort(words,sizeof(words)/sizeof(words[0]),sizeof(words[0]),compare2);
    
    for(i=0;i<N;i++)
    {
        if(strcmp(words[i],last) == 0)
        {
            continue;
        }
        else if(i!=N-1)
        {
            printf("%s\n",words[i]);
            strcpy(last,words[i]);
        }   
        else
        {
            printf("%s",words[i]);
        }
    }
    return 0;
}