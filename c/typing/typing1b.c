#include <time.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void) {
    int i;
    char *str = "How do you do?";
    int len = strlen(str);

    init_getputch();
    printf("Please type as shown.\n");

    for (i = 0; i < len; i++) {
        printf("%s \r", &str[i]);
        fflush(stdout);
        while(getch() != str[i]);
    }

    term_getputch();
    return 0;
}