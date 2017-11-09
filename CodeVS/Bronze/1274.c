/*
 * @filename:    1274.c
 * @author:      Crow
 * @date:        11/09/2017 22:51:06
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int level,speed;

    printf("Enter the speed limit: ");
    scanf("%d",&level);
    printf("Enter the recorded speed of the car: ");
    scanf("%d",&speed);

    int judge = speed - level;
    if(judge <= 0)
        printf("Congratulations, you are within the speed limit");
    else if(judge <= 20)
        printf("You are speeding and your fine is $ 100");
    else if (judge <= 30)
        printf("You are speeding and your fine is $ 270");
    else
        printf("You are speeding and your fine is $ 500");


    return 0;
}
