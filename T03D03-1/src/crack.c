#include <stdio.h>

int main(){
    double a, b;
    char c;
    if (scanf("%lf %lf%c", &a, &b, &c) && (c == '\n')) {
        if(a*a + b*b <= 25){
            printf("GOTCHA");
        }else{
            printf("MISS");
        }
    }else{
        printf("n/a");
    }
    printf("\n");
    return 0;
}