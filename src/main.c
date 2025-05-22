#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "project.h"

int main(void)
{
	//BRD *board = import function

	BRD board;
	board.width = 10;
	board.height = 7;
	board.poschar[POSY] = 1;
	board.poschar[POSX] = 2;
	board.posmch[POSY] = 4;
	board.posmch[POSX] = 3;

	board.data = malloc(board.height * sizeof(char *));
	for(int y = 0; y < board.height; y++)
		board.data[y] = malloc(board.width * sizeof(char));

	char init[7][10] = {
		{'-','-','-','-','-','-','-','-','-','-'},
		{'|',' ','#',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ','*',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
		{'-','-','-','-','-','-','-','-','-','-'},
	};

	for(int y = 0; y < board.height; y++)
		for(int x = 0; x < board.width; x++)
			board.data[y][x] = init[y][x];

	char c;
	while((c = getch()) != 27)
	{
		//Sleep(250);
		get_input(&board, c);
		
		//reset board

		for(int i = 0; i < board.height; i++)
		{
			printf("\033[A");
			printf("\033[2K");
		}

		//print board
		for(int i = 0; i < board.height; i++)
		{
			printf("\n");
			for(int j = 0; j < board.width; j++)
				printf("%c", board.data[i][j]);
		}
		

		//mouche

		//reset et reprint
	}
}
