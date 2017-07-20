/*************************************************************************
	> File Name: B.c
	> Author: 
	> Mail: 
	> Created Time: Thu 20 Jul 2017 09:33:06 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[1000];
    int character,flag,T;
    int i, j, x;
    char temp;

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        gets(str);
        str[strlen(str)] = '\0';
        flag = 0;
        for(character = 0;character <= strlen(str);character++)
        {
            if(str[character] != ' ' && flag == 0)
            {
                i = character;
                flag = 1;
            }
            if(str[character] == ' ' || str[character] == '\0')
            {
                if(flag != 1)
                continue;
                j = character-1;
                flag = 0;
                for(x = 0;x < (j-i+1)/2;x++)
                {
                    temp = str[i+x];
                    str[i+x] = str[j-x];
                    str[j-x] = temp;
                }
            }
        }
        printf("%s\n",str);
    }

    return 0;
}
