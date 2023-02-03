#include <iostream>
using namespace std;

int main()
{
    int ret = 0;
    string str;
    cin >> str;
    if(str[0] == '1')
    {
        if(str[1] == '0')
        {
            ret += 10;
        }
        else
        {
            ret += str[0] - '0';
        }
    }
    else
    {
        ret += str[0] - '0';
    }
    
    if(ret == 10)
    {
        if(str[2] == '1')
        {
            if(str[3] == '0')
            {
                ret += 10;
            }
            else
            {
                ret += str[2] - '0';
            }
        }
        else
        {
            ret += str[2] - '0';
        }
    }
    else
    {        
        if(str[1] == '1')
        {
            if(str[2] == '0')
            {
                ret += 10;
            }
            else
            {
                ret += str[1] - '0';
            }
        }
        else
        {
            ret += str[1] - '0';
        }
    }
    
    printf("%d", ret);
    
    return 0;
}