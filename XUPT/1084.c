#include<stdio.h>
int main(void)
{
    long num,result;

    while(scanf("%ld",&num) != EOF)
    {
	  if(num <= 100000)
	  {
        result = num*0.1;
	    printf("%d\n",result);
	    continue;
	  }
	  if(num >= 100000 && num <= 200000)
	  {
	    result = 10000+(num-100000)*0.075;
	    printf("%d\n",(long)result);
	    continue;
	  }
	  if(num >= 200000 && num <= 400000)
	  {
	    result = 20000+(num-200000)*0.05;
	    printf("%d\n",(long)result);
	    continue;
	  }
	  if(num >= 400000 && num <= 600000)
	  {
	    result = 40000+(num-400000)*0.03;
	    printf("%d\n",(long)result);
	    continue;
	  }
	  if(num >= 600000 && num <= 1000000)
	  {
	    result = 60000+(num-600000)*0.15;
	    printf("%d\n",(long)result);
	    continue;
	  }
      if(num > 1000000)
      {
        result = 100000+(num-1000000)*0.01;
        printf("%ld\n",(long)result);
      }
    }
}

/* 一道纯水题,课后题
*
* 毫无意义,仅仅用来
*
* 刷题目量(笑)
*
*/
