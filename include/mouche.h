#ifndef MOUCHE_H
#define MOUCHE_H

#define CHILL 15

//move
int move(BRD *board, int dx, int dy);
int test_move(BRD *board, int new_x, int new_y);

//moveset
int idle(BRD *board, int c_y, int c_x, int m_y, int m_x);
int y_axis(BRD *board, int c_y, int c_x, int m_y, int m_x);
int x_axis(BRD *board, int c_y, int c_x, int m_y, int m_x);
int corner(BRD *board, int c_y, int c_x, int m_y, int m_x);
int def(BRD *board, int c_y, int c_x, int m_y, int m_x);
void new_offset(int *new, int cpos, int mpos);

//utils
int range_calc(int c_y, int c_x, int m_y, int m_x);

//mouche
void mouche(BRD *board, char c);

#endif
