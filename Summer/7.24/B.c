#include<stdio.h>
long long gcd(long long a,long long b);
long long lcm(long long a,long long b);
int main(void)
{
   int T;
   long long a,b,c,d;

   scanf("%d",&T);
   getchar( );
   while(T--)
   {
      scanf("%ll/%ll %ll/%ll",&a,&b,&c,&d);
      int t;
      t = gcd(a,b);
      a /= t;
      b /= t;
      t = gcd(c,d);
      c /= t;
      d /= t;
      if(gcd(b,d) == 1)
         printf("%ll\n",lcm(a,c));
      else
         printf("%ll/%ll\n",lcm(a,c),gcd(b,d));
   }

   return 0;
}

long long gcd(long long a,long long b)
{
   if(b = 0)
   return a;
   else
      return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
   return a/gcd(a,b)*b;
}
