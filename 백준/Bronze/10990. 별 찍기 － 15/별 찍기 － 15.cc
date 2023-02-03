#include <iostream>
using namespace std;

int main()
{
    int N, left=0, mid=0;
    cin >> N;
    left = N-1;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<left;j++)
            cout << " ";
        cout << "*";
        for(int j=0;j<mid;j++)
            cout << " ";
        if(mid!=0)
        {
            cout << "*";
            mid+=2;
        }
        else
            mid++;
        left--;
        if(i!=N-1)
            cout << endl;
    }
    
    return 0;
}