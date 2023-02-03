# include <stdio.h>

int main()
{
    unsigned long long r1, r2;
    scanf("%llu %llu",&r1,&r2);
    printf("%llu",(r1*r1)-(2*r1*r2));
    return 0;
}