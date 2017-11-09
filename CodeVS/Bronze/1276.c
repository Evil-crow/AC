/*
 * @filename:    1276.c
 * @author:      Crow
 * @date:        11/09/2017 23:24:05
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int k;

    scanf("%d",&k);
    for ( int j = 0; j < k; j++ ) {
        for( int t = 0;t < k; t++ )
            printf("*");
        for( int t = 0;t < k; t++ )
            printf("x");
        for( int t = 0;t < k; t++ )
            printf("*");
        printf("\n");
    }
    for( int j = 0 ;j < k; j++ ) {
        for( int t = 0; t < k; t++ )
            printf(" ");
        for( int t = 0; t < k; t++ )
            printf("xx");
        printf("\n");
    }
    for( int j = 0; j < k; j++ ) {
        for( int t = 0; t < k; t++ )
            printf("*");
        for( int t = 0; t < k; t++ )
            printf(" ");
        for( int t = 0; t < k; t++ )
            printf("*");
        printf("\n");
    }
}
