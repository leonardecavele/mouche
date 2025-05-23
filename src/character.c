#include "project.h"
#include "character.h"

int get_input(BRD *board, char c)
{
	int win;
    if(c == 'q')
        {
            win = move(board, -1, 0);
        }
        else if(c == 'd')
        {
            win = move(board, 1, 0);
        }
        else if(c == 'z')
        {
            win = move(board, 0, -1);
        }
        else if(c == 's')
        {
            win = move(board, 0, 1);
        }
		return win;
}

int move(BRD *board, int dx, int dy)
{
	int y = board->poschar[POSY];
    int x = board->poschar[POSX];

	int new_y = y + dy;
	int new_x = x + dx;

    if(new_x < 0 || new_x >= board->width || new_y < 0 || new_y >= board->height)
		return 1;
    
	char target = board->data[new_y][new_x];
	if(target != ' ' && target != '*')
		return 1;

	board->data[new_y][new_x] = '#';
    board->data[y][x] = ' ';
    board->poschar[POSX] = new_x;
	board->poschar[POSY] = new_y;

	if(target == '*')
		return 0;
	return 1;
}
