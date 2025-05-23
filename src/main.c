#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "project.h"

void flush_input_buffer(); //todo

void anim(); //todo

void win(); //todo

void flush_input_buffer() //todo
{
    while (_kbhit()) getch();
}

void anim() //tdoo
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

void win() //todo
{
	anim();
	exit(0);
}

int main(void)
{
	srand(time(NULL));
	BRD board;

    if (!parse_map(&board)) {
        fprintf(stderr, "Parsing Error. Check map validity\n");
        return (1);
    }

	char c;
	while((c = getch()) != 27)
	{
		mouche(&board, c);
		int win_con = get_input(&board, c);
		flush_input_buffer();
		reset_board(board.height);
		print_board(board.height, board.width, board.data);
		if (!win_con)
			win();
	}
	reset_board();
}
