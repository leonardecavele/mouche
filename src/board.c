#include <stdio.h>
#include "project.h"

void reset_board(int height)
{
	printf("\033[%dA", height);
	for(int i = 0; i < height; i++)
    {
        printf("\033[2K");
		printf("\033[1B");
    }
	printf("\033[%dA", height);
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
