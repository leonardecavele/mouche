#include <stdlib.h>
#include "project.h"
#include "mouche.h"

int range_calc(int c_y, int c_x, int m_y, int m_x)
{
	int y_higher = (c_y > m_y) ? c_y : m_y;
	int y_lower = (c_y > m_y) ? m_y : c_y;
	int x_higher = (c_x > m_x) ? c_x : m_x;
	int x_lower = (c_x > m_x) ? m_x : c_x;

	return (y_higher - y_lower) + (x_higher - x_lower);
}
