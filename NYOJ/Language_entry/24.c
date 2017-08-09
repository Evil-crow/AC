#include<stdio.h>
#include<math.h>
int judge(int );                   //判断是否为素数
int main(void)
{
    long long M,n,length,num;
    int i;
    scanf("%lld",&M);
    getchar(  );
    while(M--)
    {
        i = 0;
        scanf("%lld",&n);
        while(1)
        {
            if(n == 0)
            {
                length = 2;
                num = 2;
                break;
            }
            if(n == 1 )
            {
                length = 1;
                num = 2;
                break;
            }
            if(judge(n-i))
            {
                length = i;
                num = n-i;
                break;
            }
            if(judge(n+i))
            {
                length = i;
                num = n+i;
                break;
            }
            i++;
            continue;
        }
        printf("%lld %d\n",num,length);
    }

    return 0;
}

int judge(int n)
{
    int t;
    for(t = 2;t <= sqrt(n);t++)
    {
        if(n%t == 0)
        return 0;
    }
    return 1;
}

/* 此题的坑点在于0,1的判断,另外对判断素数的算法
 *
 * 进行优化,使用sqrt(  ),可以提高一倍的速度
 *
 * 否则,会超时TLE
 *
 */
 
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
	for(int k=2;k<=sqrt((double)n);k++)
		if((n%k)==0)
			return false;
	return true;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int num,i,j;		
		cin>>num;
		if(num==1)
		{
			cout<<"2 1"<<endl;
			continue;
		}
		for(i=num;!isprime(i);i--);	
		for(j=num;!isprime(j);j++);	
		
		if((num-i)<(j-num))
			cout<<i<<' '<<(num-i)<<endl;
		else if((num-i)>(j-num))
			cout<<j<<' '<<(j-num)<<endl;
		else if((num-i)==(j-num))
			cout<<i<<' '<<(num-i)<<endl;
	}
}        

