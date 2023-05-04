#include <stdio.h>
#include <stdlib.h>

#include <ncurses.h>

/* Number matrix */
	const bool number[][15] =
	{
		{1,1,1,1,0,1,1,0,1,1,0,1,1,1,1}, /* 0 */
     	{0,0,1,0,0,1,0,0,1,0,0,1,0,0,1}, /* 1 */
     	{1,1,1,0,0,1,1,1,1,1,0,0,1,1,1}, /* 2 */
     	{1,1,1,0,0,1,1,1,1,0,0,1,1,1,1}, /* 3 */
     	{1,0,1,1,0,1,1,1,1,0,0,1,0,0,1}, /* 4 */
     	{1,1,1,1,0,0,1,1,1,0,0,1,1,1,1}, /* 5 */
     	{1,1,1,1,0,0,1,1,1,1,0,1,1,1,1}, /* 6 */
     	{1,1,1,0,0,1,0,0,1,0,0,1,0,0,1}, /* 7 */
     	{1,1,1,1,0,1,1,1,1,1,0,1,1,1,1}, /* 8 */
     	{1,1,1,1,0,1,1,1,1,0,0,1,1,1,1}, /* 9 */
};


void
draw_number(int n, int x, int y) 
{
    // Recuperar la matriz de booleanos que representa el número
    const bool* num = number[n];

    // Pintar el número en la posición especificada
    for (int i = 0; i < 15; i++)
	{
        for (int j = 0; j < 5; j++)
		{
            // Si la matriz indica que el pixel debe estar activado,
            // se pinta un asterisco en la posición correspondiente
            if (num[i * 5 + j]) 
			{
                mvprintw(y + i, x + j, "^");
            }
        }
    }
}

int
main()
{
	
	initscr();
	
	curs_set(0);
	draw_number(2, 14, 4);
	//mvprintw(20, 20, "Hola, esta es una ventana ncurses");

	refresh();
	
	getch();

	endwin();

	return 0;
}
