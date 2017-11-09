/*
 * @filename:    1275.c
 * @author:      Crow
 * @date:        11/09/2017 22:59:58
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int a,b,c,d;

    scanf("%d %d %d %d",&a,&b,&c,&d);
    if((a == b) && (b == c) && (c == d)) {
        printf("Fish At Constant Depth");
        return 0;
    }
    if((b < a) && (c < b) && (d < c)) {
        printf("Fish Diving");
        return 0;
    }
    if((b > a) && (c > b) && (d > c)) {
        printf("Fish Rising");
        return 0;
    }
    else
        printf("No Fish");

    return 0;
}
