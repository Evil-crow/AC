#include<stdio.h>
int gcd(int T,int a);
int main(void)
{
    int i,T;
    char ch;
    int a,b,c;
    scanf("%d",&T);
    for(i = 1;i <= T;i++)
    {
        if(ch = getchar(  ) == 'U')
        a++;
        if(ch = getchar(  ) == 'D')
        b++;
        if(ch = getchar(  ) == 'S')
        {
            printf("Bingo");
            return 0;
        }
    }
    if((float)a/T > 0.503 || (float)a/T < 0.497)
        printf("Fail");
    else
    printf("%d/%d",a/gcd(T,a),T/gcd(T,a));

    return 0;
}

int gcd(int T,int a)
{
    if(a == 0)
    return T;
    return gcd(a,T%a);
}
