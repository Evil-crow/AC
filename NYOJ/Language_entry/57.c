#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int calculate(int );
int main(void)
{
    int N,num,result;

    scanf("%d",&N);
    getchar(  );
    while(N--)
    {
        num = 0;
        scanf("%d",num);
        result = num; 
        while(1)
        {
            result =  calculate(result);
            num++;
            printf("%d %d\n",result,num);
            if(!result)
            break;
            else
            continue;
        }
        printf("%d\n",num);
    }

    return 0;
}

int calculate(int a)
{
    char str[5];
    str[0] = a/1000;
    str[1] = a%1000/100;
    str[2] = a%1000%100/10;
    str[3] = a%1000%100%10;
    str[4] = '\0';
    int i,j,m,n,x;
    char temp;
    for(i = 0;i < 3;i++)
        for(j = i;j < 3-i;j++)
        {
            if(str[j] > str[j+1])
            {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    printf("%s ",str);
    m = atoi(str);
    for(i = 0;i < 3;i++)
        for(j = i;j < 3-i;j++)
        {
            if(str[j] < str[j+1])
            {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    printf("%s ",str);
    n = atoi(str);
    x = n-m;

    return x;    
}
