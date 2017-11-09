/*
 * @filename:    1203.c
 * @author:      Crow
 * @date:        11/08/2017 23:15:50
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char ch,a[8],b[8];
    int i = 0,j = 0;

    while(ch = getchar(  ) != '.')
        continue;
    ch = getchar(  );
    while(i != 8) {
        a[i++] = ch;
        ch = getchar(  );
    }

    while(ch = getchar(  ) != '.')
        continue;
    ch = getchar(  );
    while(j != 8) {
        b[j++] = ch;
        ch = getchar(  );
    }

    for(int t = 0;t < 8;t++) {
        if(a[t] != b[t]) {
            printf("no");
            return 0;
        }
    }
    printf("yes");

    return 0;
}
