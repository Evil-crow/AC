#include<stdio.h>

int check(int *,int );                      //判断是否正在睡觉

int main(void)
{
    int T;
    int arr[10][3];                         //保存作息周期
    int i;                                  //循环计数用
    int time;                               //时间计数
    int stu;                                //睡觉学生计数
    int flag1,flag2;                        //不能再睡觉的标记

    scanf("%d",&T);
    while(T != 0)
    {
        time = 1;
        for(i = 0;i < T;i++)
            scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
        int q[T];
        flag
        while(1)
        {
            time++;
            stu = 0;
            flag1 = 0;
            for(i = 0;i < T;i++)
            {
                if(flag1 == 1)
                {
                    if(q[i] = check(arr[i],time))
                    {
                        if(flag2 == 0)
                            time++;
                        else
                            flag2 == 1;
                    }
                }
                if(q[i] = check(arr[i],time))
                    stu++;
                if(stu <= T/2)
                    flag1 = 1;
            }
            printf("序号%d: %d\n",i-1,stu);
            if(flag1 == 1 && flag2 == 0)
                break;
            if(time > 100)
            {
                time = -1;
                break;
            }
        }

        printf("time is %d\n",time+1);
        scanf("%d",&T);
    }

    return 0;
}

int check(int *arr,int time)
{
    int status[100];
    int i = 0;
    int num;
    int str[arr[0] + arr[1]];
    int a,b,c;

    a = arr[0];b = arr[1];
    while(i < a+b)
    {
        while(a--)
        {
            str[i] = 0;
            i++;
        }
        while(b--)
        {
            str[i] = 1;
            i++;
        }
    }
    num = arr[2]-1;
    a = arr[0];b = arr[1];
    for(i = 0;i < a+b-(arr[2]-1);i++)
    status[i] = str[num++];
    while(i < 100)
    {
        a = arr[0];
        b = arr[1];

        while(a--)
        {
            status[i] = 0;
            i++;
        }
        while(b--)
        {
            status[i] = 1;
            i++;
        }
    }

    return status[time-1];
}
