#include <stdlib.h>
#include "project.h"
#include "mouche.h"

int idle_memory = 0;

int idle(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
	int range = range_calc(c_y, c_x, m_y, m_x); //condition
	if(range < CHILL)
		return 1;

	int dx = rand() % 3 - 1;
	int dy = rand() % 3 - 1;

	if(++idle_memory == 2)
	{
		dx = -dx;
		dy = -dy;
		idle_memory = 0;
	}

	if(m_y == 1)
		dy = 1;
	else if(m_y == board->height - 2)
		dy = -1;
	else if(m_x == 1)
		dx = 1;
	else if(m_x == board->width - 2)
		dx = -1;

	if(move(board, dx, dy))
		return 0;
	return 1;
}

int y_axis(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
    int new_x = 0;
    //condition
    if(c_y >= m_y - CHILL && c_y <= m_y + CHILL)
    {
        if(c_x < m_x)
        {
            new_offset(&new_x, c_x, m_x);
            if(move(board, new_x, 0))
                return 0;
        }
        else if(c_x > m_x)
        {
            new_offset(&new_x, c_x, m_x);
            if(move(board, new_x, 0))
                return 0;
        }
        else
        {
            new_x = (rand() % 2 == 0) ? -1 : 1;
            if(move(board, new_x, 0))
                return 0;
        }
    }
    return 1;
}

int x_axis(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
    int new_y = 0;
    //condition
    if(c_x >= m_x - CHILL && c_x <= m_x + CHILL)
    {
        if(c_y < m_y)
        {
            new_offset(&new_y, c_y, m_y);
            if(move(board, 0, new_y))
                return 0;
        }
        else if(c_y > m_y)
        {
            new_offset(&new_y, c_y, m_y);
            if(move(board, 0, new_y))
                return 0;
        }
        else
        {
            new_y = (rand() % 2 == 0) ? -1 : 1;
            if(move(board, 0, new_y))
                return 0;
        }
    }
    return 1;
}

int corner(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
    int dx = 0, dy = 0;
	int r = rand() % 2;
	int r2 = rand() % 4;
	int r3 = rand() % 6;

    if(m_y == 1 && m_x == 1) //haut gauche
    {
		if(c_x < c_y)
			dx = 1;
		else if(c_x > c_y)
			dy = 1;
		else if(c_x == c_y)
		{
			if(r == 0)
				dy = 1;
			else
				dx = 1;
			if(r2 == 2)
			{
				dx = 1;
				dy = 1;
			}
			else if(r3 == 0)
            {
                dx = 0;
                dy = 0;
            }
		}
    }
	else if(m_y == 1 && m_x == (board->width - 2)) //haut droit
	{
		if(c_y > ((board->width - 2) - c_x))
			dx = -1;
		else if(c_y < ((board->width - 2) - c_x))
			dy = 1;
		else if(c_y == ((board->height - 2) - c_x)) //to verify
		{
			if(r == 0)
				dy = 1;
			else
				dx = -1;
			if(r2 == 2)
			{
				dx = -1;
				dy = 1;
			}
			else if(r3 == 0)
			{
				dx = 0;
				dy = 0;
			}
		}
	}

	else if(m_y == (board->height -2) && m_x == 1) //bas gauche
	{	
		if(c_x > (board->height - c_y))
			dy = -1;
		else if(c_x < (board->height - c_y))
			dx = 1;
		else if(c_x == (board->height - c_y)) //to verify
		{
			if(r == 0)
				dy = -1;
			else
				dx = 1;
			if(r2 == 2)
			{
				dx = 1;
				dy = -1;
			}
			else if(r3 == 0)
			{
				dx = 0;
				dy = 0;
			}
		}
	}
	else if(m_y == (board->height -2) && m_x == (board->width -2)) //bas droit
	{	
		if((board->width - c_x) < (board->height) - c_y)
			dx = -1;
		else if((board->height - c_y) < (board->width - c_x))
			dy = -1;
		else if((board-> height - c_y) == (board->height - c_x)) 
		{
			if(r == 0)
				dy = -1;
			else
				dx = -1;
			if(r2 == 2)
			{
				dx = -1;
				dy = -1;
			}
			else if(r3 == 0)
			{
				dx = 0;
				dy = 0;
			}
		}
	}
    else
		return 1;

    if(move(board, dx, dy))
        return 0;
    return 1;
}

int def(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
    int dx = 0, dy = 0;
    int r = rand() % 2;

    if(c_y < m_y)
        dy = 1;  //bas
    else if(c_y > m_y)
        dy = -1; //haut
    if(c_x < m_x)
        dx = 1;  //droite
    else if(c_x > m_x)
        dx = -1; //gauche

    if(r == 0)
	{
        if(move(board, dx, 0)) return 0;  //x
        if(move(board, 0, dy)) return 0;
    }
	else
	{
        if(move(board, 0, dy)) return 0;  //y
        if(move(board, dx, 0)) return 0;
    }

    if(move(board, dx, dy))
		return 0;
	return 1;
}

void new_offset(int *new, int cpos, int mpos)
{
	if(cpos < mpos) {
		*new = 1;
	}
	else if(cpos > mpos) {
		*new = -1;
	}
}
