# include <stdio.h>
int queue[2000001]={0,}, head=1, tail=1;

void push(int X)
{
    queue[tail++]=X;
}

int pop()
{
    if(head!=tail)
        return queue[head++];
    else
        return -1;
}

int size()
{
    return tail-head;
}

int empty()
{
    if(head!=tail)
        return 0;
    else
        return 1;
}

int front()
{
    if(head==tail)
        return -1;
    else
        return queue[head];
}

int back()
{
    if(head==tail)
        return -1;
    else
        return queue[tail-1];
}

int main()
{
    int N, x, i;
    char order[10];
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++)
    {
        scanf("%s",order);
        if(order[0]=='p' && order[1]=='u')
        {
            scanf("%d",&x);
            push(x);
        }
        else if(order[0]=='p' && order[1]=='o')
        {
            printf("%d\n",pop());
        }
        else if(order[0]=='s')
        {
            printf("%d\n",size());
        }
        else if(order[0]=='e')
        {
            printf("%d\n",empty());
        }
        else if(order[0]=='f')
        {
            printf("%d\n",front());
        }
        else
        {
            printf("%d\n",back());
        }
    }
    
    return 0;
}