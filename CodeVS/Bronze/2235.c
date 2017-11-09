/*
 * @filename:    2235.c
 * @author:      Crow
 * @date:        11/08/2017 23:29:35
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int price;
    float result;

    scanf("%d %f",&price,&result);
    printf("%d %.2f",price,result);
    result *= price;
    result /= 10.0;
    printf("result = %f",result);
    float temp = result;
    while(temp - 1 > 0) {
        temp--; 
    }
    int integer = result - temp;
    if(integer%100%10 < 5)
        integer -= integer%100%10;
    else
        integer += (10 - integer%100%10);

    printf("%d",integer);

    return 0;
}
