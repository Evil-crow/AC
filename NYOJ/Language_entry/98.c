#include<stdio.h>
int main(void)
{
    int T,num;
    char a;
    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        scanf("%d",&num);
        if(num >=90 && num <= 100)
        a = 'A';
        else if(num >= 80)
        a = 'B';
        else if(num >= 70)
        a = 'C';
        else if(num >= 60)
        a = 'D';
        else if(num >= 0)
        a = 'E';
        printf("%c\n",a);
    }

    return 0;
}

/* 使用switch case也可以进行解决
 *
 */



#include<iostream>
using namespace std;
int main()
{
int n,s;
cin>>n;
while(n--)
{
cin>>s;
switch(s/10)
{
case 10:
case 9:cout<<"A"<<endl;break;
case 8:cout<<"B"<<endl;break;
case 7:cout<<"C"<<endl;break;
case 6:cout<<"D"<<endl;break;
default:cout<<"E"<<endl;break;
}
}
}
