#ifndef MOUCHE_H
#define MOUCHE_H

int move(BRD *board, int dx, int dy);
int test_move(BRD *board, int new_x, int new_y);

int range_calc(int c_y, int c_x, int m_y, int m_x);
void new_op(int *new, int range, int cpos, int mpos);

int idle(BRD *board, int c_y, int c_x, int m_y, int m_x);
int corner(BRD *board, int c_y, int c_x, int m_y, int m_x);
int diag(BRD *board, int c_y, int c_x, int m_y, int m_x);

int y_axis(BRD *board, int c_y, int c_x, int m_y, int m_x);
int x_axis(BRD *board, int c_y, int c_x, int m_y, int m_x);

void mouche(BRD *board, char c);

#endif
