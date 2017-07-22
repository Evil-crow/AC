#include<stdio.h>
int main(void)
{
   int N,t;
   char phone[20];

   scanf("%d",&N);
   getchar( );
   while(N--)
   {
      scanf("%s",phone);
      printf("%d",6);
      for(t = 6;t < 11;t++)
         printf("%c",phone[t]);
      printf("\n");
   }

   return 0;
}
