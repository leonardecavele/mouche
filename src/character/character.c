#include "project.h"
#include "character.h"

void get_input(BRD *board, char c)
{
    if(c == 'q')
        {
            move(board, -1, 0);
        }
        else if(c == 'd')
        {
            move(board, 1, 0);
        }
        else if(c == 'z')
        {
            move(board, 0, -1);
        }
        else if(c == 's')
        {
            move(board, 0, 1);
        }
}

void move(BRD *board, int dx, int dy)
{
	int y = board->poschar[POSY];
    int x = board->poschar[POSX];

	int new_y = y + dy;
	int new_x = x + dx;

    if(new_x < 0 || new_x >= board->width || new_y < 0 || new_y >= board->height)
        return;
    
	char target = board->data[new_y][new_x];
	if(target != ' ' && target != '*')
		return;

	board->data[new_y][new_x] = '#';
    board->data[y][x] = ' ';
    board->poschar[POSX] = new_x;
	board->poschar[POSY] = new_y;

	//mouche win
}
