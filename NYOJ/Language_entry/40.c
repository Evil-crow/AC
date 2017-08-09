#include<stdio.h>
int Gcd(int ,int );
int main(void)
{
    int N;
    int a,b,_gcd,lcm;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d %d",&a,&b);
        _gcd = Gcd(a,b);
        lcm = a/_gcd*b;
        printf("%d %d\n",_gcd,lcm);
    }

    return 0;
}

int Gcd(int a,int b)
{
    if(b == 0)
    return a;
    else
    return Gcd(b,a%b);
}

/* 此题的重点在于对gcd与lcm的理解
 * 
 * gcd利用欧几里得算法,递归版本,可大幅提高效率
 * 
 * 如上所示
 * 
 * 而且,注意求解lcm时,先除后乘,防止溢出情况
 */
  
#include<stdio.h>
int main()
{
	unsigned int u,v,r,s,i,d;
	scanf("%u",&s);
	for(i=1;i<=s;i++)
	{
		scanf("%u%u",&u,&v);
		d=u*v;
		while(v!=0)
		{
			r=u%v;
			u=v;
			v=r;
		}
		printf("%u %u\n",u,d/u);
	}
	return 0;
}        