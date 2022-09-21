#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int N;
int cnt = 1;
string last;
vector<string> v;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string file;
        cin >> file;
        v.push_back(file.substr(file.find(".")+1));
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<v.size();i++)
    {
        if(v[i].compare(last)==0)
        {
            cnt++;
        }
        else
        {
            if(i!=0)
            {
                cout << cnt << "\n";
                cnt = 1;
            }
            cout << v[i] << " ";
            last = v[i];
        }
    }
    cout << cnt;
    
    return 0;
}