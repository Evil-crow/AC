#include<stdio.h>
int main(void)
{
    char str[7];

    while(scanf("%s",str) != EOF)
    {
        if(str[0] == '0')
        {
            printf("%c%c%c\n",str[5],str[6],str[7]);
            break;
        }
        if(str[4] == '0')
        {
            printf("%c%c%c\n",str[0],str[1],str[2]);
            break;
        }
        if(str[2] == str[6])
        {
            
    }
}
