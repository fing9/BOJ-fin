#include <iostream>

using namespace std;

int main()
{
    char matrix[101][101], c;
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for(int i=0;i<n;i++)
    {
        scanf("%c", &c);
        for(int j=0;j<m;j++)
        {
            scanf("%c", &c);
            
            if(c == '-') c = '|';
            else if(c == '|') c = '-';
            else if(c == '/') c = '\\';
            else if(c == '\\') c = '/';
            else if(c == '^') c = '<';
            else if(c == '<') c = 'v';
            else if(c == 'v') c = '>';
            else if(c == '>') c = '^';
            
            matrix[j][i] = c;
        }
    }
    
    
    for(int i=m-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c", matrix[i][j]);
        }
        if(i!=0)
            printf("\n");
    }
    
    return 0;
}