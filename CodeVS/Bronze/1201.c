/*
 * @filename:    1201.c
 * @author:      Crow
 * @date:        11/08/2017 18:08:27
 * @description:
 */

#include<stdio.h>
#include<stdlib.h>
int main(void) {
    int n,i,min,max,temp;
    scanf("%d",&n);
    getchar(  );

    scanf("%d",&temp);
    min = temp;
    max = temp;
    for( i = 0;i < n-1; i++ ) {
        scanf("%d",&temp);
        if( temp > max )
            max = temp;
        if( temp < min )
            min = temp;
    }
    printf("%d %d",min,max);

    return 0;
}

