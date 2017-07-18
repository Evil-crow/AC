/*************************************************************************
	> File Name: A.c
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Jul 2017 10:42:23 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char mail[100];
    int length;
    char answer;

    while(scanf("%s",mail) != EOF)
    {
        answer = 'q';
        int t = 0;
        int flag = 0;
        length = strlen(mail);
        for(t = 0;t < length;t++)
        {
            if(mail[0] == '@' || mail[0] == '.' || mail[length-1] == '@' || mail[length-1] == '.')
            {
                answer = 'n';
                break;
            }
            if(mail[t] == '@' && flag == 0)
            {
                flag = 1;
                continue;
            }
            if(mail[t] == '.' && mail[t+1] == '@' )
            {
                answer = 'n';
                break;
            }
            if(mail[t] == '.' && mail[t-1] == '@' )
            {
                answer = 'n';
                break;
            }
            if(mail[t] == '@' && flag == 1)
            {
                answer = 'n';
                break;
            }
            if(mail[t] == '.' && flag == 1)
            answer = 'w';
        }
        if(answer == 'w')
        printf("YES\n");
        else
        printf("NO\n");
    }

    return 0;
}
