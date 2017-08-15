#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    int T;
    int i,j;
    char str[90],loop[4];
    int temp;

    scanf("%d",&T);
    getchar( );
    while(T--)
    {
        int number[4] = {0};
        gets(str);
        for(i = 0;str[i] != '\0';i++)
        {
            if(str[i] == 'C')
            {
                if(str[i+1] == '\0' || str[i+1] > 64 )
                {
                    number[0]++;
                    continue;
                }
                if(str[i+1] < 58)
                {
                    j = 0;
                    memset(loop,0,90);
                    while(str[i+1] < 58)
                    {
                        loop[j++] = str[++i];
                    }
                    loop[j] = '\0';

                    temp = atoi(loop);
                    number[0] += temp;
                }

                continue;
            }
            if(str[i] == 'H')
            {
                if(str[i+1] == '\0' || str[i+1] > 64 )
                {
                    number[1]++;
                    continue;
                }
                if(str[i+1] < 58)
                {
                    j = 0;
                    memset(loop,0,90);
                    while(str[i+1] < 58)
                    {
                        loop[j++] = str[++i];
                    }
                    loop[j] = '\0';

                    temp = atoi(loop);
                    number[1] += temp;
                }
            }
            if(str[i] == 'O')
            {
                if(str[i+1] == '\0' || str[i+1] > 64 )
                {
                    number[2]++;
                    continue;
                }
                if(str[i+1] < 58)
                {
                    j = 0;
                    memset(loop,0,90);
                    while(str[i+1] < 58)
                    {
                        loop[j++] = str[++i];
                    }
                    loop[j] = '\0';

                    temp = atoi(loop);
                    number[2] += temp;
                }
            }
            if(str[i] == 'N')
            {
                if(str[i+1] == '\0' || str[i+1] > 64 )
                {
                    number[3]++;
                    continue;
                }
                if(str[i+1] < 58)
                {
                    j = 0;
                    memset(loop,0,90);
                    while(str[i+1] < 58)
                    {
                        loop[j++] = str[++i];
                    }
                    loop[j] = '\0';

                    temp = atoi(loop);
                    number[3] += temp;
                }
            }
        }
        printf("%d %d %d %d\n",number[0],number[1],number[2],number[3]);
        printf("%.3lf\n",12.01*number[0]+1.008*number[1]+16.00*number[2]+14.01*number[3]);
    }
    return 0;
}
