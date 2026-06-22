#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#include "value.h"
#include "string.h"
#define StrLength 100
int main(void)
{
    static int flagsetTest; 
    char pre[20];
    char str[10000][20];
    int preindex[10000];
    char ch;
    int i,j,index,temp = 0;
    while((ch=getchar()) != '\n') {
        if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'))) {
            str[i][j] = ch;
            str[i][j + 1] = '\0';
            j++;
        } else if ((ch == ' ') || (ch == '\'')) {
            str[i][j] = '\0';
            i++;
            j = 0;
        } else {

        }
    }
    for (int k = 0; k <= i ; k++) {
        printf("%s ",str[k]);
    }
    printf("\n");
    scanf("%[^\n]",&pre[0]);

    for (int k = 0; k <= i ; k++) {
        for (int q = 0; q < strlen(pre); q++) {
            if (str[k][q] != pre[q])
                break;
            if (q == strlen(pre) - 1) {
                preindex[index] = k;
                index++;
            }
        }
    }
    if (index == 0) {
        printf("%s",pre);
    } else {
        for (int k = 0; k < index; k++) {
            for (int q = k + 1; q < index; q++) {
                if (strcmp(str[preindex[k]],str[preindex[q]]) > 0) {
                    temp = preindex[k];
                    preindex[k] = preindex[q];
                    preindex[q] = temp;
                }
            }
        }
        printf("%s ",str[preindex[0]]);
        for (int k = 1; k < index ; k++) {
            if (strcmp(str[preindex[k]],str[preindex[k-1]]) == 0) {

            } else if (k == index - 1){
                printf("%s",str[preindex[k]]);
            } else {
                printf("%s ",str[preindex[k]]);
            }
        }        
    }
    return 0;
}