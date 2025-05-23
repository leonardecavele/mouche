#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "project.h"

void flush_input_buffer();

void win();

void flush_input_buffer()
{
    while (_kbhit()) getch();
}

void win(int height)
{
	reset_board(height);
	printf("\033[H\033[J");
	exit(0);
}

int main(void)
{
	//BRD *board = import function

	BRD board;
	board.width = 16;
	board.height = 7;
	board.poschar[POSY] = 1;
	board.poschar[POSX] = 2;
	board.posmch[POSY] = 4;
	board.posmch[POSX] = 3;

	board.data = malloc(board.height * sizeof(char *));
	for(int y = 0; y < board.height; y++)
		board.data[y] = malloc(board.width * sizeof(char));

	char init[7][16] = {
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
		{'|',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
	};

	for(int y = 0; y < board.height; y++)
		for(int x = 0; x < board.width; x++)
			board.data[y][x] = init[y][x];

	char c;
	while((c = getch()) != 27)
	{
		//mouche

		Sleep(100);
		int win_con = get_input(&board, c);
		flush_input_buffer();
		reset_board(board.height);
		print_board(board.height, board.width, board.data);
		if (!win_con)
			win(board.height);
	}
}
