/*
 * @filename:    1023.c
 * @author:      Crow
 * @date:        11/09/2017 22:02:36
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n;
    float score,sum,a,b;
    
    sum = 0;
    scanf("%d",&n);
    for( int t = 0; t < n; t++ ) {
        scanf("%f %f",&a,&b);
        score += a;
        sum += a*b;
    }
    printf("%.2f",sum/score);

    return 0;
}
