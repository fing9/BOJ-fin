#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ans = "UCPC";
    string inp, ret = "";
    int mode = 0;

    getline(cin, inp);

    for(int i = 0;i<inp.length();i++)
    {
        if(mode == 0 && inp[i] == 'U')
        {
            ret += 'U';
            mode++;
        }
        else if (mode == 1 && inp[i] == 'C')
        {
            ret += 'C';
            mode++;
        }
        else if (mode == 2 && inp[i] == 'P')
        {
            ret += 'P';
            mode++;
        }
        else if (mode == 3 && inp[i] == 'C')
        {
            ret += 'C';
            break;
        }
    }

    if(ret.compare(ans) == 0)
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";
    
    return 0;
}