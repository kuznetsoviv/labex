#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define QNO 12

#define swap(type, x, y) do {type t = x; x= y; y = t; } while (0)

int main(void) {
    char *str[QNO] = {"book", "computer", "default", "comfort",
                      "monday", "power", "light", "music",
                      "programming", "dog", "video", "include"};
    
    int i, stage;
    int qno[QNO];
    init_getputch();
    srand(time(NULL));
    for (i = 0; i < QNO; i++)
        qno[i] = i;
    for (i = QNO - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        if (i != j)
            swap(int, qno[i], qno[j]);
    } 
    
    printf("Start typing practice.\n");
    printf("Press the spacebar to begin.\n");
    while(getch() != ' ')
        ;
    for (stage = 0; stage < QNO; stage++) {
        int len =  strlen(str[qno[stage]]);
        for (i = 0; i < len; i++) {
            printf("%s \r", &str[qno[stage]][i]);
            fflush(stdout);
            while(getch() != str[qno[stage]][i])
                ;
        }
    }
    term_getputch();
    return 0;
    
}