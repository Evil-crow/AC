#include<stdio.h>
#include<string.h>
int main(void)
{
    int T;
    char arr[1000];
    char a[1000],b[1000],c[10000];
    int t,i,j,k;

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        i = 0;j = 0;k = 0;
        scanf("%s",arr);
        for(t = 0;arr[t] != '\0';t++)
        {
            if(arr[t] == 'R')
                a[i++] = arr[t];
            if(arr[t] == 'W')
                b[j++] = arr[t];
            if(arr[t] == 'B')
                c[k++] = arr[t];
        }
        a[i] = '\0';
        b[j] = '\0';
        c[k] = '\0';
        strcat(a,b);
        strcat(a,c);
        printf("%s\n",a);
    }

    return 0;
}

/* 我的处理方法是最贴近传统的解法
 *
 * 比较好理解,但是使用效率不高
 *
 * 下面的这种解法很棒
 *
 * 用两个变量记录了"W""B"的个数
 *
 * 最后,直接用循环输出
 *
 * 值得学习
 *
 */



 
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		int w=0,b=0;
		char c;
		while((c=getchar())!=10)
			c=='R'?printf("R"):(c=='W'?w++:b++);
		while(w--)
			putchar('W');
		while(b--)
			putchar('B');
		printf("\n");
	}
}        
