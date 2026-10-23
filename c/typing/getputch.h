#ifndef __GETPUTCH_H__
#define __GETPUTCH_H__

#if defined(_WIN32) || defined(_WIN64)

#include <conio.h>

#define init_getputch() ((void)0)
#define term_getputch() ((void)0)
#define getch()         _getch()
#define putch(ch)       _putch(ch)

#else

#include <curses.h>

#define init_getputch() initscr()
#define term_getputch() endwin()

#endif

#endif