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

	parse_score();

	char path[] = "./maps/map1.txt";

	reset_board();
    if (!parse_map(&board, path)) {
        fprintf(stderr, "Parsing Error. Check map validity\n");
        return 1;
    }
	print_board(board.height, board.width, board.data);

	char c;
	while((c = getch()) != 27)
	{
		mouche(&board, c);
		int win_con = get_input(&board, c);
		flush_input_buffer();
		reset_board();
		print_board(board.height, board.width, board.data);
		if (!win_con)
			win(path, &c, &board);
	}
	win(path, &c, &board);
}
