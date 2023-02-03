#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    while(N!=0)
    {
        string tmp = to_string(N);

        int left=0, right=tmp.size()-1;
        bool isFLD = true;
        while(left != right && left <= right)
        {
            if(tmp[left++]!=tmp[right--])
            {
                isFLD = false;
                break;
            }
        }
        
        if(isFLD) printf("yes\n");
        else printf("no\n");
        
        scanf("%d", &N);
    }
    
    return 0;
}