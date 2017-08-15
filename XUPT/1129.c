#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{

    char arr[100];
    long length;
    long sum,num;

    scanf("%s",arr);
    while(strcmp(arr,"0") != 0)
    {
        length = strlen(arr);
        num = arr[length-1]-'0';
        arr[length - 1] = '\0';
        sum = atol(arr);
        if((sum-num*5)%17 == 0)
        printf("1\n");
        else
        printf("0\n");
        scanf("%s",arr);
    }

    return 0;
}
