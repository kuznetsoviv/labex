#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void) {
    int i;
    char *str = "How do you do?";
    int len = strlen(str);

    init_getputch();
    printf("Please type as shown.\n");
    printf("%s\n", str);
    fflush(stdout);

    for(int i = 0; i < len; i++) {
        int ch;
        do {
            ch = getch();
            if (isprint(ch)) {
                putch(ch);
                if (ch != str[i])
                    putch('\b');
            }
        } while (ch != str[i]);
    }
    term_getputch();
    return 0;
}