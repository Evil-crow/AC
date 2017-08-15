/*************************************************************************
	> File Name: 3.c
	> Author:KVD 
	> Mail:Evilcrow486@gmail.com 
	> Created Time: 2017年06月17日 星期六 17时21分38秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void string(char *);
int main(void)
{
    int t;
    char str[100];
    scanf("%d",&t);
    getchar(  );
    while(t--)
    {
        gets(str);
        int length,word,A,a,number,space,others;

        length = strlen(str);
        int t = 0;
        int flag = 0;
        word = A = a = number = space = others = 0;
        while(str[t] != '\0')
        {
            if(str[t] != ' ' && flag == 0)
            {
                word++;
                flag = 1;
            }
            if(str[t] == ' ' && flag == 1)
            {
                flag = 0;
            }
        }
        t = 0;
        while(str[t] != '\0')
        {
            if(str[t] >= 'A' && str[t] <= 'Z')
            A++;
            if(str[t] >= 'a' && str[t] <= 'z')
            a++;
            if(str[t] >= '0' && str[t] <= '9')
            number++;
            if(str[t] == ' ')
            space++;
            else 
            others++;
        }

        printf("%d %d %d %d %d %d %d\n",length,word,A,a,number,space,others);
    }

    return 0;
}
