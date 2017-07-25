#include<stdio.h>
long long gcd(long long a,long long b);

int main(void)
{
   int T,a,b,t;
   scanf("%d",&T);
   getchar( );

   while(T--)
   {
      t = 0;
      scanf("%d %d",&a,&b);
      for(t = 0;t < a;t++)
      { 
         if(gcd(a,t) == b)
         {
            if(t == b)
               continue;
            if(t != b)
               break;
         } 
      }
      printf("%d\n",t);
   }

   return 0;
}

long long gcd(long long a,long long b)
{
   if(b == 0)
      return a;
   else
      return (gcd(b,a%b));
}

