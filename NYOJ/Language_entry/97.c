#include<stdio.h>
int main(void)
{
    int T;
    float M,X,Y,Z;
    float length;
    
    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        scanf("%f %f %f %f",&M,&X,&Y,&Z);
        length = (M*X*Z)/(Y-X);
        printf("%.2f\n",length);
    }
}


 
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int s,a,b,c;
		cin>>s>>a>>b>>c;
		printf("%.2lf\n",s*a/(double)(b-a)*c);
	}

}        
