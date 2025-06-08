#include <stdlib.h>
#include "project.h"
#include "mouche.h"

int move(BRD *board, int dx, int dy)
{
	int y = board->posmch[POSY];
    int x = board->posmch[POSX];

    int new_y = y + dy;
    int new_x = x + dx;

	if(test_move(board, new_x, new_y))
		return 0;
	
	board->data[new_y][new_x] = '*';
	board->data[y][x] = ' ';

	board->posmch[POSX] = new_x;
	board->posmch[POSY] = new_y;

	return 1;
}

int test_move(BRD *board, int new_x, int new_y)
{
	if(new_x < 0 || new_x >= board->width || new_y < 0 || new_y >= board->height) {
		return 1;
	}

	char target = board->data[new_y][new_x];
    if(target != ' ') {
        return 1;
	}

	return 0;
}
