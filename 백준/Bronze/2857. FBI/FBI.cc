#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v(6);
    bool isIn = false;
    
    for(int i=1;i<=5;i++)
    {
        cin >> v[i];
        if(v[i].find("FBI") != string::npos)
        {
            isIn = true;
            cout << i;
            if(i != 5)
                cout << " ";
        }
    }
    
    if(!isIn)
        cout << "HE GOT AWAY!";
    
    return 0;
}