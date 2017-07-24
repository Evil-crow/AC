#include<stdio.h>
int main(void)
{
   int min;
   char str[10000];
   int ptr[7] = {0};

   int t;
   gets(str);
   while(str[t] != '\0')
   {
      if(str[t] == 'B')
         ptr[0]++;
      else if(str[t] == 'u')
         ptr[1]++;
      else if(str[t] == 'l')
         ptr[2]++;
      else if(str[t] == 'b')
         ptr[3]++;
      else if(str[t] == 'a')
         ptr[4]++;
      else if(str[t] == 's')
         ptr[5]++;
      else if(str[t] == 'r')
         ptr[6]++;
      t++;
   }
   ptr[1] /=2;
   ptr[4] /=2;
   min = ptr[0];
   for(t = 0;t < 7;t++)
   {
      if(ptr[t] < min)
         min = ptr[t];
   }


   printf("%d\n",min);

   return 0;
}
