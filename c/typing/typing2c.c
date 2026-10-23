#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define QNO 12
#define swap(type, x, y) do {type t = x; x = y; y = t; } while (0)

int main(void) {
    char *str[QNO] = {"book", "computer", "default", "comfort",
        "monday", "power", "light", "music",
        "programming", "dog", "video", "include"
    };

    int i, stage;
    init_getputch();
    srand(time(NULL));

    for (int i = QNO - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        if (i != j)
            swap(char *, str[i], str[j]);
    }

    printf("Start Typing Practice. \n");
    printf("Press the spacebar to begin.\n");
    while( getch() != ' ')
        ;

    for (stage = 0; stage < QNO; stage++) {
        int len = strlen(str[stage]);
        for (int i = 0; i < len; i++) {
            printf("%s \r", &str[stage][i]);
            fflush(stdout);
            while(getch() != str[stage][i])
                ;
        }
    }

    term_getputch();
    return 0;
}