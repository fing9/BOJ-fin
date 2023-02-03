#include <iostream>
using namespace std;

int main()
{
    int n, i, j, sps=0, star=0;
    cin >> n;
    star=(n*2)-1;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<sps;j++)
            cout << " ";
        for(j=0;j<star;j++)
            cout << "*";
        sps++;
        star-=2;
        if(i!=n-1)
            cout << endl;
    }
    
    return 0;
}