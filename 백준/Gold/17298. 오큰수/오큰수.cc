#include <iostream>
#include <stack>
using namespace std;
stack<int> stk1, stk2, ret;

int main()
{
    int N, element;
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
    {
        int num;
        scanf("%d", &num);
        stk1.push(num);
    }
    
    ret.push(-1);
    stk2.push(stk1.top());
    stk1.pop();
    
    for(int i=0; stk1.empty()==false; i++)
    {
        element = stk1.top();
        stk1.pop();
        for(int j=0; stk2.empty()==false; j++)
        {
            if(element < stk2.top())
            {
                ret.push(stk2.top());
                stk2.push(element);
                break;
            }
            else
            {
                stk2.pop();
                if(stk2.empty())
                {
                    ret.push(-1);
                    stk2.push(element);
                    break;
                }
            }
        }
    }
    
    for(int i=0; ret.empty()==false; i++)
    {
        printf("%d ", ret.top());
        ret.pop();
    }
    
    return 0;
}