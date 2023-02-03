# include <stdio.h>

int main()
{
    int a, b, c, d, e, answer, sum;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    sum = (a*a) + (b*b) + (c*c) + (d*d) + (e*e);
    answer = sum % 10;
    printf("%d",answer);
    return 0;
}