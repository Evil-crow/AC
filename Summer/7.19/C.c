/*************************************************************************
	> File Name: C.c
	> Author: 
	> Mail: 
	> Created Time: Wed 19 Jul 2017 10:19:24 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[1000];
    int n, t;
    int length;
    int num;

    scanf("%d",&n);
    getchar(  );
    while(n--)
    {
        num = 0;
        fgets(str,1000,stdin);
        length = strlen(str);
        str[length-1] = '\0';
        for(t = 0;t < length;t++)
        {
            if(str[t] < 0)
            num++;
        }

        printf("%d\n",num/2);
    }

    return 0;
}
