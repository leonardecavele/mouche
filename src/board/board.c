#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "project.h"

void flush_input_buffer()
{
    while (_kbhit()) getch();
}

void anim()
{
	reset_board();
	for(int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			printf("\033[32mGG!\033[0m");
		else
			printf("\r\033[2K");
		fflush(stdout);
		Sleep(300);
	}
}

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
		printf("[%s] Map %d - Moves: %d", new_player, new_score_count, new_move_count++);
	fflush(stdout);
}
