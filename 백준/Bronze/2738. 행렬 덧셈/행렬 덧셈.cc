#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int A[101][101];
    cin >> N >> M;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin >> A[i][j];
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            int num;
            cin >> num;
            A[i][j] += num;
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
