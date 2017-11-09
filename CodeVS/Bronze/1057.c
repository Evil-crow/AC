/*
 * @filename:    1057.c
 * @author:      Crow
 * @date:        11/09/2017 22:13:33
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int rest = 0,month = 12,cost;
    float save = 0;

    while(month--) {
        scanf("%d",&cost);
        rest += (300 - cost);
        if(rest < 0){
            printf("-%d",12-(month));
            return 0;
        }
        save += (rest/100)*100;
        rest -= (rest/100)*100;
    }
    float result = save*1.2+rest;
    printf("%.0f",result);

    return 0;
}
