# include <stdio.h>
# include <string.h>
# define MAX_STACK_SIZE 10001

int stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty()
{
    if(top<0)
        return 1;
    else
        return 0;
}

int IsFull()
{
    if(top>=MAX_STACK_SIZE)
        return 1;
    else
        return 0;
}

void push(int value)
{
    if(IsFull()==1)
        printf("스택이 가득 찼습니다.");
    else
        stack[++top]=value;
}

int pop()
{
    if(IsEmpty()==1)
        return -1;
    else
        return stack[top--];
}


int main()
{
    int N, i, order_num;
    char order[6];
    
    scanf("%d",&N);
    
    for(i=0;i<N;i++)
    {
        scanf("%s",order);
        if(strcmp(order,"push")==0)
        {
            scanf("%d",&order_num);
            push(order_num);
        }
        else if(strcmp(order,"pop")==0)
        {
            printf("%d\n",pop());
        }
        else if(strcmp(order,"size")==0)
        {
            printf("%d\n",top+1);
        }
        else if(strcmp(order,"empty")==0)
        {
            printf("%d\n",IsEmpty());
        }
        else if(strcmp(order,"top")==0)
        {
            if(top == -1)
                printf("-1\n");
            else
                printf("%d\n",stack[top]);
        }
    }
    return 0;
}