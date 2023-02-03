#include <iostream>
#include <cstdio>
using namespace std;
int heap[400002], q_size=0;

void q_push(int data)
{
    int temp;
    temp = ++q_size;
    
    while(temp!=1 && heap[temp/2]>data)
    {
        heap[temp]=heap[temp/2];
        temp/=2;
    }
    
    heap[temp]=data;
    return;
}

void q_pop()
{
    int temp;
    int parent, child;
    
    temp=heap[q_size--];
    parent=1;
    child=parent*2;
    
    while(child<=q_size && (temp>heap[child] || temp>heap[child+1]))
    {
        if(heap[child]<heap[child+1])
        {
            if(temp>heap[child])
            {
                heap[parent]=heap[child];
                parent=child;
                child=parent*2;
            }
        }
        else
        {
            if(temp>heap[child+1])
            {
                heap[parent]=heap[child+1];
                parent=child+1;
                child=parent*2;
            }
        }
    }
    
    heap[parent]=temp;
    return;
}

int main()
{
    int N, x;
    scanf("%d",&N);
    
    for(int i=0;i<N;++i)
    {
        scanf("%d",&x);
        if(x==0)
        {
            if(q_size==0)
            {
                printf("0");
            }
            else
            {
                printf("%d",heap[1]);
                q_pop();
            }
            if(i!=N-1)
                printf("\n");
        }
        else
        {
            q_push(x);
        }
    }
    
    return 0;
}