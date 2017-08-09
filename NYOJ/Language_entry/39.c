#include<stdio.h>
int main(void)
{
    int n,a,b,c;

    scanf("%d",&n);
    getchar(  );
    while(n != 0)
    {
        a = n/100;
        b = n%100/10;
        c = n%100%10;
        if(n == a*a*a+b*b*b+c*c*c)
        printf("Yes\n");
        else
        printf("No\n");
        scanf("%d",&n);
    }

    return 0;
}


/*此题为刷过很多次的 真$入门题,不予置评*/
/*以下为C++,解法,说实话,这个人的代码风格,我很不喜欢*/
 
#include<iostream>
using namespace std;
int main()
{
	int a;
	while(1)
	{
		cin>>a;
		if(a==0) break;
		cout<<((a==153||a==370||a==371||a==407)?"Yes":"No")<<endl;
	}
}        
