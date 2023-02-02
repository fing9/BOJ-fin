#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int map[11][11];
bool flag;

void input()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char inp;
            scanf("%c", &inp);

            map[i][j] = inp - '0';
        }
        getchar();
    }
}

void print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

bool test(int y, int x, int num) {
    int baseY = (y/3) * 3;
    int baseX = (x/3) * 3;

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(map[baseY + i][baseX + j] == num)
                return false;
        }
    }

    for(int i=0;i<9;i++) {
        if (map[i][x] == num || map[y][i] == num)
            return false;
    }

    return true;
}

void backTracking(int y, int x) {
    if(flag) return;
    if(y == 9 && x == 0) {
        print();
        flag = true;
        return;
    }

    if(map[y][x] != 0) {
        if(x == 8)
            backTracking(y+1, 0);
        else
            backTracking(y, x+1);
        if (flag)
            return;
    }
    else {
        for(int i=1;i<=9;i++) {
            if(test(y, x, i)) {
                map[y][x] = i;
                if (x == 8)
                    backTracking(y + 1, 0);
                else
                    backTracking(y, x + 1);
                if (flag)
                    return;
                map[y][x] = 0;
            }
        }
    }
}

int main() {
    input();

    backTracking(0, 0);
    return 0;
}