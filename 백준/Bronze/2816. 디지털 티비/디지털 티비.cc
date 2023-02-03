#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<string> q;

int main()
{
    int add1, add2;
    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        string inp;
        string tmp1="KBS1";
        string tmp2="KBS2";
        cin >> inp;
        if(inp.compare(tmp1)==0) add1=i;
        else if(inp.compare(tmp2)==0) add2=i;
        q.push_back(inp);
    }
    
    for(int i=0;i<add1;i++)
    {
        cout << 1;
    }
    for(int i=0;i<add1;i++)
    {
        cout << 4;
    }
    
    if(add1>add2)
    {
        add2++;
    }
    
    for(int i=0;i<add2;i++)
    {
        cout << 1;
    }
    for(int i=0;i<add2-1;i++)
    {
        cout << 4;
    }
    
    return 0;
}