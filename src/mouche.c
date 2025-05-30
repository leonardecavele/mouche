#include <stdlib.h>
#include <stdio.h> //to remove
#include "project.h"

#define CHILL_VALUE 40
#define FEAR_VALUE 20
#define SUPER_FEAR 10
#define MEGA_FEAR 5

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

int range_calc(int c_y, int c_x, int m_y, int m_x)
{
	int y_higher = (c_y > m_y) ? c_y : m_y;
	int y_lower = (c_y > m_y) ? m_y : c_y;
	int x_higher = (c_x > m_x) ? c_x : m_x;
	int x_lower = (c_x > m_x) ? m_x : c_x;

	return (y_higher - y_lower) + (x_higher - x_lower);
}

int idle(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
	int new_x, new_y;

	//condition d'execution
	int range = range_calc(c_y, c_x, m_y, m_x);

	if(range < FEAR_VALUE)
		return 1;

	//calcul position
	if((rand() % 2) > 0)
	{
		new_x = (rand() % 3) + (m_x - 1);
		new_y = (rand() % 3) + (m_y - 1);
	}
	else
	{
		int r = rand() % 2;
		int r2 = (r == 0) ? 1 : 0;
		new_x = (r == 0) ? (m_x - 1) : (m_x + 1); 
		new_y = (r2 == 0) ? (m_y - 1) : (m_y + 1);
	}

	if(test_move(board, new_x, new_y)) //test validite
        return 1;

	if(range >= CHILL_VALUE)
		return 0;

	//move execute
	board->data[new_y][new_x] = '*';
	board->data[m_y][m_x] = ' ';

	board->posmch[POSX] = new_x;
	board->posmch[POSY] = new_y;
	return 0;
}

int y_axis(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
    int range = range_calc(c_y, c_x, m_y, m_x);
    int new_x = 0;

    //condition
    if(c_y >= m_y - 1 && c_y <= m_y + 1)
    {
        if(c_x < m_x)
        {
            new_op(&new_x, range, c_x, m_x);
            if(move(board, new_x, 0))
                return 0;
        }
        else if(c_x > m_x)
        {
            new_op(&new_x, range, c_x, m_x);
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

void new_op(int *new, int range, int cpos, int mpos)
{
    if(range < SUPER_FEAR)
    {
        if(cpos < mpos) {
            *new = 1;
		}
        else if(cpos > mpos) {
            *new = -1;
        }
	}
    else if(range < MEGA_FEAR) {
            if(cpos < mpos) {
                *new = 1;
			}
            else if (cpos > mpos) {
                *new = -1;
			}
	}
}

int x_axis(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
    int range = range_calc(c_y, c_x, m_y, m_x);
    int new_y = 0;

    //condition
    if(c_x >= m_x - 1 && c_x <= m_x + 1)
    {
        if(c_y < m_y)
        {
            new_op(&new_y, range, c_y, m_y);
            if(move(board, 0, new_y))
                return 0;
        }
        else if(c_y > m_y)
        {
            new_op(&new_y, range, c_y, m_y);
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

    if (m_y == 1 && m_x == 1) //haut gauche
    {
        if (c_y <= m_y && c_x <= m_x) { dx = 1; dy = 1; }
        else if (c_y <= m_y) { dy = 1; }
        else if (c_x <= m_x) { dx = 1; }
        else { dx = 1; dy = 1; }
    }
    else if (m_y == 1 && m_x == board->width - 2) //haut droite
    {
        if (c_y <= m_y && c_x >= m_x) { dx = -1; dy = 1; }
        else if (c_y <= m_y) { dy = 1; }
        else if (c_x >= m_x) { dx = -1; }
        else { dx = -1; dy = 1; }
    }
    else if (m_y == board->height - 2 && m_x == 1) //bas gauche
    {
        if (c_y >= m_y && c_x <= m_x) { dx = 1; dy = -1; }
        else if (c_y >= m_y) { dy = -1; }
        else if (c_x <= m_x) { dx = 1; }
        else { dx = 1; dy = -1; }
    }
    else if (m_y == board->height - 2 && m_x == board->width - 2) //bas droite
    {
        if (c_y >= m_y && c_x >= m_x) { dx = -1; dy = -1; }
        else if (c_y >= m_y) { dy = -1; }
        else if (c_x >= m_x) { dx = -1; }
        else { dx = -1; dy = -1; }
    }
    else {
        return 1; //pas dans un coin
    }

    //tente le move
    if (move(board, dx, dy))
        return 0;
    return 1;
}

int diag(BRD *board, int c_y, int c_x, int m_y, int m_x)
{
    if(abs(c_y - m_y) != abs(c_x - m_x))
        return 1; //pas en diagonale

    int dx = 0, dy = 0;
    int r = rand() % 3;

    //déterminer la direction de la fuite
    if(c_y < m_y && c_x < m_x) { //joueur en haut gauche
        if(r == 0) { dx = 1; dy = 0; }  //droite
        else if(r == 1) { dx = 0; dy = 1; }  //bas
        else { dx = 1; dy = 1; }  //bas droite
    }
    else if(c_y < m_y && c_x > m_x) { //haut droite
        if(r == 0) { dx = -1; dy = 0; }  //gauche
        else if(r == 1) { dx = 0; dy = 1; }  //bas
        else { dx = -1; dy = 1; }  //bas gauche
    }
    else if(c_y > m_y && c_x < m_x) { //bas gauche
        if(r == 0) { dx = 1; dy = 0; }  //droite
        else if(r == 1) { dx = 0; dy = -1; }  //haut
        else { dx = 1; dy = -1; }  //haut droite
    }
    else if(c_y > m_y && c_x > m_x) { //bas droite
        if(r == 0) { dx = -1; dy = 0; }  //gauche
        else if(r == 1) { dx = 0; dy = -1; }  //haut
        else { dx = -1; dy = -1; }  //haut gauche
    }

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

    if(r == 0) {
        if(move(board, dx, 0)) return 0;  //x
        if(move(board, 0, dy)) return 0;
    } else {
        if(move(board, 0, dy)) return 0;  //y
        if(move(board, dx, 0)) return 0;
    }

    if (move(board, dx, dy)) return 0;

    return 1;
}

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
