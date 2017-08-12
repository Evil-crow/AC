#include<stdio.h>
#include<math.h>
int main(void)
{
    int T;
    float a,b,c,d,result;

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        scanf("%f %f %f %f",&a,&b,&c,&d);
        result = (c-a)*(c-a) + (d-b)*(d-b);
        printf("%.2f\n",sqrt(result));
    }

    return 0;
}

/* 这道题的问题在实数
 *
 * 进行数据类型的定义时,谨慎对待
 *
 * float即可
 *
 */
 
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	/*freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);*/

double x1,x2,y1,y2,m;
double a;
cin>>m;
while(m--)
{
	cin>>x1>>y1>>x2>>y2;
    a=sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	cout.setf(ios::fixed); 
    cout<<setprecision(2)<<a<<endl;
}
return 0;
}
 

        
