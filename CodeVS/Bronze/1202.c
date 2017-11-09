/*
 * @filename:    1201.c
 * @author:      Crow
 * @date:        11/08/2017 18:08:27
 * @description:
 */

#include<stdio.h>
#include<stdlib.h>
int main(void) {
    int n,i,sum,temp;
    scanf("%d",&n);
    getchar(  );
    
    sum = 0;
    for( i = 0;i < n; i++ ) {
        scanf("%d",&temp);
        sum += temp;
    }
    printf("%d",sum);

    return 0;
}
