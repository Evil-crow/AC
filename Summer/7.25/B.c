#include<string.h>
#include<stdio.h>
int main(void)
{
   int T,t,temp,flag,length;
   char a[1000],b[1000],c[1000];
   scanf("%d",&T);
   while(T--)
   {
      temp = 0;
      flag = 0;
      scanf("%s %s",a,b);
      length = strlen(a);
      for(t = length - 1;t > 0;t--)
      {
         c[t] = a[t] + b[t] + temp;
         if(c[t] > '9')
         {
            c[t]-=10;
            temp = 1;
         }
         if(t == 0 && c[t] > '9')
         {
            flag = 1;
         }
      }
      if(T == 0)
      {
         if(flag == 1)
            printf("Case %d:\n1%s + %s = %s",T,a,b,c);
         else
            printf("Case %d:\n%s + %s = %s",T,a,b,c);
      }
      else
      {
         if(flag == 1)
            printf("Case %d:\n1%s + %s = %s\n",T,a,b,c);
         else
            printf("Case %d:\n%s + %s = %s\n",T,a,b,c);
      }
   }

   return 0;
}
