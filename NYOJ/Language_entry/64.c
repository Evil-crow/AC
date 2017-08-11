#include<stdio.h>
int main(void)
{
    int T;

    int n,m,a,b;
    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        scanf("%d %d",&n,&m);
        if(n*2 < m && (m-2*n)%2 == 0)
        {
            b = (m-2*n)/2;
            a = n-b;
            printf("%d %d\n",a,b);
        }
        else
        printf("No answer\n");
    }

    return 0;
}

/* 此题核心在于算法,只要知晓如何进行计算即可
 *
 * 其中需要注意的点
 *
 * 中断原则的顺序,以及|| 和 && 逻辑运算符的恰当使用
 *
 * 最后,水题..
 *
 */
 
#include<iostream>
using namespace std;
int main()
{
   int n,a,b,p,q;
   cin>>n;
   while(n--)
   {
      cin>>a>>b;
      q=(b-2*a)/2;
      p=a-q;
      if(p<0 ||q<0 || b%2) cout<<"No answer"<<endl;
      else cout<<p<<" "<<q<<endl;
   }
}                        
