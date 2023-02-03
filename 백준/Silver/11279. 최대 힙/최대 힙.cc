#include <iostream>
#include <stdio.h>
#define MAX_ELEMENT 100005 // 힙 안에 저장된 요소의 개수
using namespace std;

typedef struct element{
    int key;
};

typedef struct HeapType{
    element heap[MAX_ELEMENT];
    int heap_size;
};

void insert_max_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size); // 힙 크기를 하나 증가
    
    while((i!=1) && (item.key > h->heap[i/2].key))
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

int delete_max_heap(HeapType *h)
{
    int parent, child;
    element item, temp;
    
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    
    while(child <= h->heap_size)
    {
        if( (child < h->heap_size) && ((h->heap[child].key) < h->heap[child+1].key) )
        {
            child++;
        }
        if( temp.key >= h->heap[child].key )
        {
            break;
        }
        
        h->heap[parent] = h->heap[child];
        
        parent = child;
        child *= 2;
    }
    
    h->heap[parent] = temp;
    
    return item.key;
}

int main()
{
    int N;
    element num;
    HeapType maxheap = {{0,},0};
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&num.key);
        if(num.key != 0)
            insert_max_heap(&maxheap, num);
        else
        {
            if(maxheap.heap_size!=0)
            {
                printf("%d",delete_max_heap(&maxheap));
            }
            else
                printf("0");
            if(i!=N)
                printf("\n");
        }
    }
    
    return 0;
}