# include <stdio.h>
int queue[10001]={0,}, head=0, tail=0;

int main()
{
    int N, node, i;
    char ip[6];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",ip);
        if(ip[0]=='p' && ip[1]=='u')
        {
            scanf("%d",&node);
            queue[tail++]=node;
        }
        else
        {
            if(ip[0]=='p' && ip[1]=='o')
            {
                if(head!=tail)
                {
                    printf("%d\n",queue[head]);
                    queue[head++]=0;
                }
                else
                {
                    printf("-1\n");
                }
            }
            else if(ip[0]=='s')
            {
                printf("%d\n",tail-head);
            }
            else if(ip[0]=='e')
            {
                if(head!=tail)
                {
                    printf("0\n");
                }
                else
                {
                    printf("1\n");
                }
            }
            else if(ip[0]=='f')
            {
                if(head!=tail)
                {
                    printf("%d\n",queue[head]);
                }
                else
                {
                    printf("-1\n");
                }
            }
            else
            {
                if(head!=tail)
                {
                    printf("%d\n",queue[tail-1]);
                }
                else
                {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}