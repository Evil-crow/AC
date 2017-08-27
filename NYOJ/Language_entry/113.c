#include<stdio.h>
int main(void)
{
    char string[1000],change[1000];
    int i,j,t;

    while(fgets(string,1000,stdin) != NULL)
    {
        for(i = 0,j = 0;string[i] != '\0';i++)
        {
            if(string[i] == 'y')
            {
                t = i;
                printf("%d\n",t);
                if(string[t++] == 'o')
                {
                    if(string[t++] == 'u')
                    {
                        change[j++] = 'w';
                        change[j++] = 'e';
                        continue;
                    }
                }
            }
            change[j++] = string[i];
        }
        fputs(change,stdout);
    }

    return 0;
}
