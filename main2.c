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

void draw_number(int n, int x, int y)
{
    // Recuperar la matriz de booleanos que representa el número
    const bool* num = number[n];

    // Activar los colores y estilo correspondiente
    attron(COLOR_PAIR(1)); // activar el par de colores definido previamente
    attron(A_BOLD);        // activar negrita

    // Pintar el número en la posición especificada
    for (int row = 0; row < 15; row++) {
        for (int col = 0; col < 15; col++) {
            if (num[row * 15 + col]) {
                // Si el valor en la matriz es verdadero, pinta un asterisco en la posición correspondiente
                mvprintw(y + row, x + col, "*");
            }
        }
    }
}

int
main()
{
	
	initscr();
	
	curs_set(0);
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	draw_number(2, 10, 10);
	//mvprintw(20, 20, "Hola, esta es una ventana ncurses");

	refresh();
	
	getch();

	endwin();

	return 0;
}
