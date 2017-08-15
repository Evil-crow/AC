/*************************************************************************
	> File Name: 1.c
	> Author:KVD 
	> Mail:Evilcrow486@gmail.com 
	> Created Time: 2017年06月17日 星期六 15时46分58秒
 ************************************************************************/

#include<stdio.h>
int min(int ,int );
int main(void)
{
    int a, b, c,temp;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d %d %d",a,b,c);
    temp = min(a,b);
    temp = min(temp,c);
    printf("%d",temp);

    return 0;
}
int min(int x, int y)
{
    int temp;
    int i,j;
    i = x;
    j = y;

    temp = i%j;
    while(temp != 0)
    {
        i = j;
        j = temp;
        temp = i%j;
    }

    return x*y/j;

}
