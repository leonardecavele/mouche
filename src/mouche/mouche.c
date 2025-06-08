#include <stdlib.h>
#include "project.h"
#include "mouche.h"

void mouche(BRD *board, char c)
{
	int c_y = board->poschar[POSY];
	int c_x = board->poschar[POSX];

	if(c == 'q')
	{
		c_x = board->poschar[POSX] - 1;
	}
	else if(c == 'd')
	{
		c_x = board->poschar[POSX] + 1;
	}
	else if(c == 'z')
	{
		c_y = board->poschar[POSY] - 1;
	}
	else if(c == 's')
	{
		c_y = board->poschar[POSY] + 1;
	}

	int m_y = board->posmch[POSY];
	int m_x = board->posmch[POSX];

	if(!(corner(board, c_y, c_x, m_y, m_x))) {
		//printf("corner\n");
		return;
	}
	else if(!(y_axis(board, c_y, c_x, m_y, m_x))) {
		//printf("y\n");
		return;
	}
	else if(!(x_axis(board, c_y, c_x, m_y, m_x))) {
		//printf("x\n");
		return;
	}
	else if(!(diag(board, c_y, c_x, m_y, m_x))) {
		//printf("diag\n");
		return;
	}
	else if(!(idle(board, c_y, c_x, m_y, m_x))) {
		//printf("idle\n");
		return;
	}
	else {
		def(board, c_y, c_x, m_y, m_x);
		//printf("def\n");
		return;
	}
}
