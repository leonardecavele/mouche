#include <windows.h>
#include <stdio.h>
#include <conio.h>

int read(char *board)
{	
	int result = -1;
	for(int i = 0; board[i] != '\0'; i++)
	{
		if(board[i] == 'W')
			result = i;
	}
	return result;
}

void reset(char *board)
{
	for(int i = 0; i < strlen(board); i++)
		printf("\b");
}

int character(void)
{
	char board[] = "       W     ";
	printf("%s", board);

	int temp;
	int c;
	while((c = getch()) != 27)
	{
		if(c == 'q')
		{
			temp = read(board);
			board[temp] = ' ';

			if(temp == 0)
				temp = strlen(board) - 1;
			else
				temp--;
			board[temp] = 'W';
			reset(board);
			printf("%s", board);
		}
		else if(c == 'd')
		{
			temp = read(board);
			board[temp] = ' ';

			if(temp == strlen(board) - 1)
				temp = 0;
			else
				temp++;

			board[temp] = 'W';
			reset(board);
			printf("%s", board);
		}
	}
}
