/*
 * @filename:    1205.c
 * @author:      Crow
 * @date:        11/09/2017 21:07:07
 * @description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char *str,int i,int j);

int main(void) {
    char str[100];
    int length;
    
    gets(str);
    length = strlen(str);
    change(str,0,length-1);

    int i = 0,j = 0;
    for(int t = 0;str[t] != '\0';t++ ) {
        while(str[t] != '\0' && str[t] != ' ') {
            j++;
            t++;
        }
        change(str,i,j-1);
        j++;
        i = j;
    }
    puts(str);

    return 0;
}

void change(char *str,int i, int j) {
    char temp;
    for(int t = 0;t <= (j-i)/2; t++) {
        temp = str[i+t];
        str[i+t] = str[j-t];
        str[j-t] = temp;
    }
}
