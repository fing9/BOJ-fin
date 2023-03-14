#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string.h>

#define INF 987654321

using namespace std;

double toDouble(const char *str) {
    char cmd[10][3] = {"A+","A0","B+","B0","C+","C0","D+","D0","F","P"};

    if (!strcmp(str, cmd[0]))
        return (4.5);
    else if (!strcmp(str, cmd[1]))
        return (4.0);
    else if (!strcmp(str, cmd[2]))
        return (3.5);
    else if (!strcmp(str, cmd[3]))
        return (3.0);
    else if (!strcmp(str, cmd[4]))
        return (2.5);
    else if (!strcmp(str, cmd[5]))
        return (2.0);
    else if (!strcmp(str, cmd[6]))
        return (1.5);
    else if (!strcmp(str, cmd[7]))
        return (1.0);
    else if (!strcmp(str, cmd[8]))
        return (0);
    else if (!strcmp(str, cmd[9]))
        return (-1);
}

int main() {
    double ans;
    double sum = 0;
    int cnt = 0;

    for (int i=0;i<20;i++) {
        char name[51], grade[10];
        double point, ret;

        scanf("%s %lf %s", name, &point, grade);
        getchar();
        ret = toDouble(grade);
        if (ret != -1) {
            cnt += point;
            sum += point * ret;
        }
    }

    ans = sum / cnt;

    printf("%.6lf", ans);

    return (0);
}