#include<stdio.h>
#include<string.h>
int main(void)
{
   int T,t,length;
   char str[1000];
   char temp[1000];
   char _temp;

   scanf("%d",&T);
   getchar( );
   while(T--)
   {
      gets(str);
      length = strlen(str);
      str[length] = '\0';
      strcpy(temp,str);
      for(t = 0;t < length/2;t++)
      {
         _temp = str[t];
         str[t] = str[length - t - 1];
         str[length - t - 1] = _temp;
      } 
      if(strcmp(str,temp) == 0)
         printf("yes\n");
      else
         printf("no\n");
   }

   return 0;
}
