#include<stdio.h>
int main(void)
{
    int t = 12;
    float num,sum = 0;

    while(t--)
    {
        scanf("%f",&num);
        sum+=num;
    }
    printf("%.2f",sum/12);

    return 0;
}

/* 第一,这道题是纯水题,毫无技术可言
 *
 * 第二,这TM是在搞事,明明题意中写道
 *
 * 需要'$'符号,结果output以及判题里
 *
 * 都不牵扯此问题,我艹
 *
 * 第三,用C++不一定就比C简单
 *
 */


#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double sum=0,a;
	for(int i=0;i<12;i++)
	{
		cin>>a;
		sum+=a;
	}
	cout<<fixed<<setprecision(2)<<sum/12.0<<endl;
}
