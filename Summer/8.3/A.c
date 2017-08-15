#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char A1[100000];
    char A2[100000];
    char B1[100000];
    char B2[100000];
    char ch;
    int i;
    int t;

    while((ch = getchar(  )) != EOF)
    {
        for(i = 0;ch != '\0' && ch != '.' && ch != '0';i++)
        {
            A1[i] = ch;
            ch = getchar(  );
        }
        A1[i] = '\0';
        for(i = 0;ch != '.' && ch != '\0';i++)
        {
            A2[i] = ch;
            ch = getchar(  );
        }
        A2[i] = '\0';
        if(ch == ' ')
            ch = getchar(  );
        for(i = 0;ch != '\0' && ch != '.' && ch != '0';i++)
        {
            B1[i] = ch;
            ch = getchar(  );
        }
        B1[i] = '\0';
        for(i = 0;i != '\0';i++)
        {
            B2[i] = ch;
            ch = getchar(  );
        }
        B2[i] = '\0';
        t = strlen(A2);
        while(t--)
        {
            if(A2[t] == '0')
                continue;
            else
                A2[t] = '\0';
        }
        t = strlen(B2);
        while(t--)
        {
            if(B2[t] == '0')
                continue;
            else
                B2[t] = '\0';
        }
        if(strlen(A1) != strlen(B1))
        {
            printf("NO\n");
            continue;
        }
        if(strcmp(A1,B1) != 0)
        {
            printf("NO\n");
            continue;
        }
        if(strcmp(A2,B2) != 0)
        {
            printf("NO\n");
            continue;
        }
        else
        {
            printf("YES\n");
            continue;
        }
    }

    return 0;
}
