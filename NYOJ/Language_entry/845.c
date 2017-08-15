#include<stdio.h>
int main(void)
{
    int a,b;
    int x = 0,y = 0,z = 0;

    scanf("%d %d",&a,&b);
    while(a != 0 && b != 0)
    {
        if(a == 1)
        x += b;
        if(a == 2)
        y += b;
        if(a == 3)
        z += b;
        scanf("%d %d",&a,&b);
    }
    printf("1 %d\n2 %d\n3 %d\n",x,y,z);

    return 0;
}
