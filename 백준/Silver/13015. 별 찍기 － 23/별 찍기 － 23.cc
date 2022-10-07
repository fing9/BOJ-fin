#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    for(int i=0;i<N;i++) {
        for(int j=0;j<i;j++)
            printf(" ");

        if(i==0) {
            for(int j=0;j<N;j++)
                printf("*");
        }
        else {
            printf("*");
            for(int j=0;j<N-2;j++)
                printf(" ");
            printf("*");
        }

        for (int j = 0; j < 1 + (N - i - 2) * 2; j++) {
            printf(" ");
        }

        if(i==0) {
            for(int j=0;j<N;j++)
                printf("*");
        }
        else {
            if(i != N-1)
                printf("*");
            for(int j=0;j<N-2;j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }

    for(int i=N-2;i>=0;i--) {
        for(int j=0;j<i;j++)
            printf(" ");

        if(i==0) {
            for(int j=0;j<N;j++)
                printf("*");
        }
        else {
            printf("*");
            for(int j=0;j<N-2;j++)
                printf(" ");
            printf("*");
        }

        for (int j = 0; j < 1 + (N - i - 2) * 2; j++) {
            printf(" ");
        }

        if(i==0) {
            for(int j=0;j<N;j++)
                printf("*");
        }
        else {
            if(i != N-1)
                printf("*");
            for(int j=0;j<N-2;j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}