#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include "project.h"

char new_player[4];
int new_move_count = 0;
int new_score_count = 1;

char best_player[4];
int best_move_count = 0;
int best_score_count = 0;

void win(char *path, char *c, BRD *board)
{
	if(*c != 27)
	{
		int i, a;
		for(i = 0; path[i] < '0' || path[i] > '9'; i++);
		a = path[i] - '0';
		path[i] = (++a + '0');

		FILE *test = fopen(path, "r");
		if(test)
		{
			fclose(test);
			reset_board();
			if (!parse_map(board, path))
			{
				fprintf(stderr, "Parsing Error. Check map validity\n");
				exit(1);
			}
			new_score_count++;
			print_board(board->height, board->width, board->data);
			return;
		}
		anim();
	}
	write_score(c);
	exit(0);
}

void parse_score()
{
	FILE *score = fopen(".hscore.txt", "r");

	if(score)
	{
		read_score(score);
		fclose(score);
	}
	get_name();
}

void read_score(FILE *score)
{
	char buffer[10];
	int c, i;
	
	for(i = 0; (c = fgetc(score)) != EOF && c != '\n' && c >= 'A' && c <= 'Z'; i++)
		best_player[i] = c;
	best_player[i] = '\0';

	for(i = 0; (c = fgetc(score)) != EOF && c!= '\n' && c >= '0' && c <= '9'; i++)
		buffer[i] = c;
	buffer[i] = '\0';
	best_move_count = atoi(buffer);

	for(i = 0; (c = fgetc(score)) != EOF && c!= '\n' && c >= '0' && c <= '9'; i++)
		buffer[i] = c;
	buffer[i] = '\0';
	best_score_count = atoi(buffer);

	reset_board();
	printf("highest score is %d level(s), held by %s with %d moves", best_score_count, best_player, best_move_count);
	Sleep(2500);
}

void write_score(char *c)
{
	reset_board();

	if(*c == 27)
		new_score_count--;

	if(new_score_count > best_score_count)
		goto write;
	else if(new_score_count == best_score_count && new_move_count < best_move_count)
		goto write;
	return;

	write:
		
		SetFileAttributes(".hscore.txt", FILE_ATTRIBUTE_NORMAL);

		int status = 1;
		FILE *test = fopen(".hscore.txt", "r");
		if(test)
			status = 0;
		fclose(test);

		FILE *new_file = fopen(".hscore.txt", "w");
		if(!new_file)
		{
			perror("fopen for write failed");
			return;
		}

		fprintf(new_file, "%s\n%d\n%d", new_player, --new_move_count, new_score_count);

		if(!SetFileAttributes(".hscore.txt", FILE_ATTRIBUTE_HIDDEN))
			perror("SetFileAttributes failed");
		fclose(new_file);
		
		if(status)
		{
			printf("you're the first to play the game on this computer");
		}
		else
		{
			printf("congratulations, you beat %s", best_player);
			if(new_score_count == best_score_count)
				printf(" with %d less move(s)", best_move_count - new_move_count);
			else if(new_score_count > best_score_count)
				printf(" with %d more level(s) done", new_score_count - best_score_count);
		}
		Sleep(2500);
		reset_board();
}

void get_name()
{
	int i, c;
	wname:
		reset_board();
		printf("pick a three-letter name\n");
		for(i = 0; i < 3; i++)
		{
			c = getchar();
			if(c == '\n' || c == EOF)
			{
				reset_board();
				printf("name too short");
				Sleep(1000);
				goto wname;
			}
			else if(c <= '9' && c >= '0')
			{
				reset_board();
				printf("numbers are not accepted");
				Sleep(1000);
				goto wname;
			}
			new_player[i] = (char)c;
		}
		new_player[i] = '\0';
		to_upper(new_player);
		reset_board();
}

void to_upper(char *str)
{
    for(int i = 0; str[i]; i++)
        str[i] = toupper((unsigned char)str[i]);
}
