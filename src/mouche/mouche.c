#include "project.h"
#include "mouche.h"

#include <stdio.h>
#include <windows.h>

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

	if(!(idle(board, c_y, c_x, m_y, m_x)))
		return;
	else if(!(corner(board, c_y, c_x, m_y, m_x)))
		return;
	else if(!(y_axis(board, c_y, c_x, m_y, m_x)))
		return;
	else if(!(x_axis(board, c_y, c_x, m_y, m_x)))
		return;
	else 
	{
		def(board, c_y, c_x, m_y, m_x);
		return;
	}
}
