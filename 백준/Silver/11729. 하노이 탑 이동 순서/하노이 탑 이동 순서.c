# include <stdio.h>
int move = 0;

void hanoi(int N, int from, int empty, int to)
{
    if(N==1)
    {
        printf("%d %d\n",from,to);
        return;
    }
    
    hanoi(N-1, from, to, empty);
    printf("%d %d\n", from, to);
    hanoi(N-1, empty, from, to);
    
    return;
}

void hanoi_num(int N, int from, int empty, int to)
{
    if(N==1)
    {
        move++;
        return;
    }
    
    hanoi_num(N-1, from, to, empty);
    move++;
    hanoi_num(N-1, empty, from, to);
    
    return;
}

int main()
{
    int N;
    scanf("%d",&N);
    hanoi_num(N, 1, 2, 3);
    printf("%d\n",move);
    hanoi(N, 1, 2, 3);
    return 0;
}