# include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d",&x,&y);
    switch(x){
        case 1:
            y+=0;
            break;
        case 2:
            y+=3;
            break;
        case 3:
            y+=3;
            break;
        case 4:
            y-=1;
            break;
        case 5:
            y+=1;
            break;
        case 6:
            y+=4;
            break;
        case 7:
            y-=1;
            break;
        case 8:
            y+=2;
            break;
        case 9:
            y+=5;
            break;
        case 10:
            y+=0;
            break;
        case 11:
            y+=3;
            break;
        case 12:
            y+=5;
            break;
    }
    switch(y % 7){
        case 0:
            printf("SUN");
            break;
        case 1:
            printf("MON");
            break;
        case 2:
            printf("TUE");
            break;
        case 3:
            printf("WED");
            break;
        case 4:
            printf("THU");
            break;
        case 5:
            printf("FRI");
            break;
        case 6:
            printf("SAT");
            break;
    }
    return 0;
}