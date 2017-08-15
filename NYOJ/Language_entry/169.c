#include<stdio.h>
#include<math.h>
int judge(int n);
int main(void)
{
    int T,num,i,flag,result;
    
    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        flag = 0;
        i = 0;
        scanf("%d",&num);
        while(flag != 1)
        {
            if(judge(num+i))
            {
                flag = 1;
                result = num+i;
                break;
            }
            if(judge(num-i))
            {
                flag = 1;
                result = num-i;
                break;
            }
            i++;
        }
        printf("%d\n",result);
    }

    return 0;
}

int judge(int n)
{
    int i,flag;
    flag == 1;
    for(i = 2;i < sqrt(n);i++)
    {
        if(n%i == 0)
        flag == 0;
    }
    printf("flag:%d\n",flag);
    return flag;
}
