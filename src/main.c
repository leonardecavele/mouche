#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "project.h"

int main(void)
{
	reset_board();
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
		reset_board();
		print_board(board.height, board.width, board.data);
		if (!win_con)
			win();
	}
	reset_board();
}
