// консольный тетрис
#include <iostream>
#include <ncurses.h>
/* #include <vector> */
/* #include "figura.hpp" */

using namespace std; 

      /* wstring  tetromino[7];                                                  // фигуры */
      /*     int  nFieldWidth  = 20;                                             // размер поля */
      /*     int  nFieldHeight = 14;                                             // размер поля */

/* vector <unsigned char> pField; */


int main(void)
{

    /* ini_figuri ( tetromino ); */
    /* ini_pole   ( nFieldWidth, nFieldHeight,  pField ); */
    /* show_pole  ( nFieldWidth, nFieldHeight,  pField ); */
    
    initscr();
    mvprintw (11,11,"привет как дела");
    endwin();

    return 0;
}
