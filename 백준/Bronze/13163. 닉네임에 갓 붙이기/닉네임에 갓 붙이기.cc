#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;

    cin >> n;
    
    string s;
    getline(cin, s);
    
    for(int i=0;i<n;i++)
    {
        string s, ans;
        int first = 0;

        getline(cin, s);
        
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == ' ' &&  first == 0)
            {
                ans = "god";
                first = 1;
            }
            else if(s[i] != ' ')
                ans += s[i];
        }
        
        cout << ans << '\n';
    }

    return 0;
}