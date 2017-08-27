#include<stdio.h>
int main(void)
{
    int n;
    int a,b,max,sum;

    scanf("%d",&n);
    getchar(  );
    while(n != 0)
    {
        max = 0;
        while(n--)
        {
            scanf("%d %d",&a,&b);
            sum = a + b;
            if(max < sum)
                max = sum;
        }
        printf("%d\n",max);
        scanf("%d",&n);
    }

    return 0;
}


/* 讲道理,下面的题解写的真丑...
 *
 * 但是,我在使用三元运算符时失败
 *
 * 可能是因为左值的问题
 *
 * 之后,可以仔细研究
 *
 */
 
#include<stdio.h>
main(){int n;while(scanf("%d",&n),n){int a,b,s=0;while(n--){scanf("%d%d",&a,&b);if(a+b>s) s=a+b;}printf("%d\n",s);}}        
