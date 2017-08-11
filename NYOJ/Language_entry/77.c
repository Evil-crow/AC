#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,k,t,i;

    scanf("%d %d",&n,&k);
    int light[n];
    memset(light,0,sizeof(light));
    for(i = 1;i <= k;i++)
    {
        for(t = i-1;t < n;t+=i)
        {
            if(light[t] == 1)
            light[t] = 0;
            else
            light[t] = 1;
        }
    }
    for(i = 0;i < n;i++)
    {
        if(light[i] == 1)
        printf("%d ",i+1);
    }
}

/* 本题思路比较明确
 *
 * 但是,有需要注意的两个点
 *
 * 1.memset一般只用于置空(0)或者置为字符
 *
 * 2.进行逻辑处理时,连用两个if最后使得
 *
 * 结果又置回来了,相当于没有进行处理
 *
 * 我艹
 *
 */
 
#include <iostream>
using namespace std;
int main()
{
	int n,k,a[1000],i;
	cin>>n>>k;
	for(i=0;i<n;i++)
		a[i]=1;
	for(i=2;i<=k;i++)
		for(int j=0;j<n;j++)
		{
			if((j+1)%i==0)
			if(a[j]==0)a[j]=1;
			else a[j]=0;
		}
		for(i=0;i<n;i++)
			if(a[i]==1)cout<<i+1<<" ";
			cout<<endl;
	return 0;
}        
