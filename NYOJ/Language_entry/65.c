#include<stdio.h>
int calculate(int n);

int main(void)
{
    int T,num,sum;

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        sum = 0;
        scanf("%d",&num);
        for(int i = 1;i <= num;i++)
            sum+=calculate(i);
        printf("%d\n",sum);
    }

    return 0;
}

int calculate(int n)
{
    int i,sum;

    sum = 1;
    for(i = 1;i <= n;i = i+2)
    sum *=i;
    return sum;
}


/* 题目思路简单明确,仔细分析,注意变量的使用
 *
 * 即可解出正确的结果
 *
 */

/* 下面这种解法,真是TM日了狗
 *
 * 就这TM还用C++,我艹
 *
 */
 
/*
#include<iostream>
using namespace std;
int f(int n)
{
	if(n%2) return n==1?1:n*f(n-2);
	return f(n-1);
}
int g(int n)
{
	return n?g(n-1)+f(n):0;
}
int main()
{
	int n,m;
	cin>>n;
	while(n--)
	{
		cin>>m;
		cout<<g(m)<<endl;
	}
}*/
#include<iostream>
using namespace std;
int main()
{
    int n,m,r[]={0,1,2,5,8,23,38,143,248,1193,2138,12533,22928,158063,293198,2320223,4347248,38806673,73266098,727995173,1382724248};
	cin>>n;
	while(n--)
	{
		cin>>m;
		cout<<r[m]<<endl;
	}
}        
