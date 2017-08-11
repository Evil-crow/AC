#include<stdio.h>
#include<math.h>
#include<string.h>
int judge(int n);

int main(void)
{
    int T;
    char word[105];
    int num[26];
    int i,j,result,temp;

    scanf("%d",&T);
    getchar(  );
    while(T--)
    {
        memset(num,0,26); 
        scanf("%s",word);
        for(i = 0;word[i] != '\0';i++)
        {
            switch(word[i])
            {
                case 'a':
                    num[0]++;
                case 'b':
                    num[1]++;
                case 'c':
                    num[2]++;
                case 'd':
                    num[3]++;
                case 'e':
                    num[4]++;
                case 'f':
                    num[5]++;
                case 'g':
                    num[6]++;
                case 'h':
                    num[7]++;
                case 'i':
                    num[8]++;
                case 'j':
                    num[9]++;
                case 'k':
                    num[10]++;
                case 'l':
                    num[11]++;
                case 'm':
                    num[12]++;
                case 'n':
                    num[13]++;
                case 'o':
                    num[14]++;
                case 'p':
                    num[15]++;
                case 'q':
                    num[16]++;
                case 'r':
                    num[17]++;
                case 's':
                    num[18]++;
                case 't':
                    num[19]++;
                case 'u':
                    num[20]++;
                case 'v':
                    num[21]++;
                case 'w':
                    num[22]++;
                case 'x':
                    num[23]++;
                case 'y':
                    num[24]++;
                case 'z':
                    num[25]++;
            }
        }
        printf("sort:\n");
        for(i = 0;i < 26;i++)
        printf("%d ",num[i]);
        printf("\n");
        for(i = 0;i < 25;i++)
            for(j = i;j < 25-i;j++)
            {
                if(num[j] < num[j+1])
                {
                    temp  = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
            }
        printf("sort:\n");
        for(i = 0;i < 26;i++)
        printf("%d ",num[i]);
        printf("\n");
        for(i = 0;i < 26;i++)
        {
            if(num[i] > 0)
            break;
        }
        result = num[0] - num[i-1];
        if(judge(result))
        printf("Lucky word\n%d\n",result);
        else
        printf("No answer\n0\n");
    }

    return 0;
}

int judge(int n)
{
    int i;
    int flag = 1;
    for(i = 2;i < sqrt(n);i++)
    {
        if(n%i == 0)
        flag = 0;
    }

    return flag;
}
