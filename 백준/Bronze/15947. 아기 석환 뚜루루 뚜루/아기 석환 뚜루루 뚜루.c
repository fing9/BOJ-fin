# include <stdio.h>

int main()
{
    int N, time, word, i;
    
    scanf("%d",&N);
    
    time = N/14;
    word = N%14;
    
    switch(word)
    {
        case 0:
            printf("sukhwan");
            break;
        case 1:
            printf("baby");
            break;
        case 2:
            printf("sukhwan");
            break;
        case 3:
            if(time>2)
            {
                printf("tu+ru*%d",time+2);
            }
            else
            {
                if(time==0)
                    printf("tururu");
                else if(time==1)
                    printf("turururu");
                else
                    printf("tururururu");
            }
            break;
        case 4:
            if(time>3)
            {
                printf("tu+ru*%d",time+1);
            }
            else
            {
                if(time==0)
                    printf("turu");
                else if(time==1)
                    printf("tururu");
                else if(time==2)
                    printf("turururu");
                else
                    printf("tururururu");
            }
            break;
        case 5:
            printf("very");
            break;
        case 6:
            printf("cute");
            break;
        case 7:
            if(time>2)
            {
                printf("tu+ru*%d",time+2);
            }
            else
            {
                if(time==0)
                    printf("tururu");
                else if(time==1)
                    printf("turururu");
                else
                    printf("tururururu");
            }
            break;
        case 8:
            if(time>3)
            {
                printf("tu+ru*%d",time+1);
            }
            else
            {
                if(time==0)
                    printf("turu");
                else if(time==1)
                    printf("tururu");
                else if(time==2)
                    printf("turururu");
                else
                    printf("tururururu");
            }
            break;
        case 9:
            printf("in");
            break;
        case 10:
            printf("bed");
            break;
        case 11:
            if(time>2)
            {
                printf("tu+ru*%d",time+2);
            }
            else
            {
                if(time==0)
                    printf("tururu");
                else if(time==1)
                    printf("turururu");
                else
                    printf("tururururu");
            }
            break;
        case 12:
            if(time>3)
            {
                printf("tu+ru*%d",time+1);
            }
            else
            {
                if(time==0)
                    printf("turu");
                else if(time==1)
                    printf("tururu");
                else if(time==2)
                    printf("turururu");
                else
                    printf("tururururu");
            }
            break;
        case 13:
            printf("baby");
            break;
    }
    return 0;
}