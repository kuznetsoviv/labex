#include <time.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

#define QNO     12

int main(void) {
    char *str[QNO] = {"book", "computer", "default", "comfort",
                      "monday", "power", "loght", "music",
                      "programming", "dog", "video", "include"};
    int i, stage;
    init_getputch();
    printf("Start typing practice.\n");
    printf("Press the spacebar  to begin.\n");
    while (getch() != ' ')
        ;

    for (stage = 0; stage < QNO; stage++) {
        int len = strlen(str[stage]);
        for (i = 0; i < len; i++) {
            printf("%s \r", &str[stage][i]);
            fflush(stdout);
            while(getch() != str[stage][i])
                ;
        }
    }
    
    term_getputch();
    return 0;

}