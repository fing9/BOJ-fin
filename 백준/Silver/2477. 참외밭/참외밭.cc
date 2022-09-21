#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    int arr[6][2];

    cin >> K;

    for(int i=0;i<6;i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        //cout << arr[i][0] << " " << arr[i][1] << "\n";
    }

    if(arr[0][0] == arr[2][0] && arr[1][0] == arr[3][0])
    {
        //cout << arr[0][1]+arr[2][1] << " * " << arr[1][1] + arr[3][1] << " - " << arr[1][1] + arr[2][1] << "\n";
        cout << K * ((arr[0][1] + arr[2][1]) * (arr[1][1] + arr[3][1]) - (arr[1][1] * arr[2][1]));
    }
    else if(arr[0][0] == arr[2][0] && arr[1][0] == arr[5][0])
    {
        cout << K * ((arr[0][1] + arr[2][1]) * (arr[1][1] + arr[5][1]) - (arr[0][1] * arr[1][1]));
    }
    else if(arr[0][0] == arr[4][0] && arr[1][0] == arr[5][0])
    {
        cout << K * ((arr[0][1] + arr[4][1]) * (arr[1][1] + arr[5][1]) - (arr[0][1] * arr[5][1]));
    }
    else if(arr[0][0] == arr[4][0] && arr[3][0] == arr[5][0])
    {
        cout << K * ((arr[0][1] + arr[4][1]) * (arr[3][1] + arr[5][1]) - (arr[4][1] * arr[5][1]));
    }
    else if(arr[2][0] == arr[4][0] && arr[3][0] == arr[5][0])
    {
        cout << K * ((arr[2][1] + arr[4][1]) * (arr[3][1] + arr[5][1]) - (arr[3][1] * arr[4][1]));
    }
    else if(arr[1][0] == arr[3][0] && arr[2][0] == arr[4][0])
    {
        cout << K * ((arr[1][1] + arr[3][1]) * (arr[2][1] + arr[4][1]) - (arr[2][1] * arr[3][1]));
    }


    return 0;
}
