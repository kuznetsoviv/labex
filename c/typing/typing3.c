#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define NO 30
#define KTYPE 16

int main(void) {
    char *kstr[] = {"12345", "67890-^\\",
        "!\"#$%", "&'() =~|",
        "qwert", "yuiop@[",
        "QWERT", "YUIOP`{",
        "asdfg", "hjkl;:]",
        "ASDFG", "HJKL+*}",
        "zxcvb", "nm,./\\",
        "ZXCVB", "NM<> _",
    };

    int i, stage;
    clock_t start, end;
    init_getputch();

    srand(time(NULL));
    printf("Start typing association exercises.\n");
    printf("Please enter the fidden character indicated by '?'.\n");
    printf("Press the space key to start.\n");
    fflush(stdout);
    while(getch() != ' ')
        ;
    start = clock();
    for (stage = 0; stage < NO; stage++) {
        int k, p, key;
        char temp[10];
        do {
            k = rand() % KTYPE;
            p = rand() % strlen(kstr[k]);
            key = kstr[k][p];
        } while (key == ' ');
        strcpy(temp, kstr[k]);
        temp[p] = '?';
        printf("%s", temp);
        fflush(stdout);
        while(getch() != key)
            ;
        putchar('\n');   
    }
    end = clock();
    printf("Time taken: %.1f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    term_getputch();
    return 0;
}