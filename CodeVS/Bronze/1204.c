/*
 * @filename:    1204.c
 * @author:      Crow
 * @date:        11/09/2017 20:08:25
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char str1[100],str2[100];
    int pos;
    int i = 0,j = 0;
    
    scanf("%s %s",str1,str2);
    while( str1[i] != '\0') {
        if( str1[i] == str2[j] ) {
            pos = i + 1;
            i++;
            j++;
            while( str1[i] == str2[j] ) {
                i++;
                j++;
                if( str2[j] == '\0' ) {
                    printf("%d",pos);
                    exit(0);
                }
            }
            i--;
            j = 0;
        }
        i++;
    }
}
