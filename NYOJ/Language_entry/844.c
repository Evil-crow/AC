#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int reversal(char *str);
int main(void)
{
    char arr1[8],arr2[8];
    int a,b;

    scanf("%s %s",arr1,arr2);
    while(strcmp(arr1,"0") != 0 && strcmp(arr2,"0") != 0)
    {
        a = reversal(arr1);
        b = reversal(arr2);
        printf("%d\n",a+b);
        scanf("%s %s",arr1,arr2);
    }

    return 0;
}

int reversal(char *str)
{
    int t;
    int length = strlen(str);
    char temp;

    for(t = 0;t < length/2;t++)
    {
        temp = str[t];
        str[t] = str[length-t-1];
        str[length-t-1] = temp;
    }

    return atoi(str);
}
