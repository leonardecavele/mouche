#include <stdio.h>
#include "project.h"

void reset_board()
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J");
    fflush(stdout);
#endif
}
void print_board(int height, int width, char **data)
{
	for(int i = 0; i < height; i++)
        {
            printf("\r");
            for(int j = 0; j < width; j++)
                printf("%c", data[i][j]);
			printf("\n");
        }
	fflush(stdout);
}
