/* https://skobki.com/yazyk-si-ncurses/ */
/* https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/intro.html#WHATIS */
/* https://invisible-island.net/ncurses/ncurses.faq.html */
/* http://www.ibiblio.org/pub/Linux/docs/HOWTO/other-formats/html_single/NCURSES-Programming-HOWTO.html#ABOUTINIT */
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <string>
#include <locale.h>
#include <libintl.h>

//g++ ./main.cpp -Wall -lncursesw

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
int main(int argc, char *argv[])
{

  setlocale(LC_ALL, "");
    initscr();			/* Start curses mode 		*/

	/* if(has_colors() == FALSE) */
	/* {	endwin(); */
	/* 	printf("Your terminal does not support color\n"); */
	/* 	exit(1); */
	/* } */
	start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);

	attron(COLOR_PAIR(1));
	print_in_middle(stdscr, LINES / 2, 0, 0, "привет мир? ёйяюцщ ");
	attroff(COLOR_PAIR(1));
    	getch();
	endwin();
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}

