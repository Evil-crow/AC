#include<stdio.h>
int main(void)
{
    int a,b,c;
    int sum,flag;

    scanf("%d %d %d",&a,&b,&c);
    flag = 0;
    for(sum = 10;sum < 100;sum++)
    {
        if(sum%3 == a && sum%5 == b && sum%7 == c)
        flag = sum;
    }
    printf("%d",flag);
    if(flag == 0)
    printf("No answer");

    return 0;
}

/* 此题核心在于遍历求解,因为数字小的关系,所以也不会超时
 *
 * 本来我的代码是很冗杂的,实际上可以进行优化
 *
 * 而且,flag的两重用法,既做了标记,也做了输出结果
 *
 * 很巧妙的用法
 *
 */

 
#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int n=(a*70+b*21+c*15)%105;
	if(n>100||n<10) cout<<"No answer"<<endl;
	else cout<<n<<endl;
}         

