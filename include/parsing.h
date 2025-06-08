#ifndef PARSING_H
#define PARSING_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//get_next_line
void    *error(char *ret);
char    *get_next_line(int fd);
//is_valid_map
void    count_spechar(BRD *board, char *str, int refline, int *nbrchar, int *nbrmch);
int     is_line_valid(char *str, int width);
int     is_minus_only(char *str);
int     is_valid_map(BRD *board, char **map);
//parsing
char    **realloc_map(char **map, int nbrlines);
char    **read_map(BRD *board, int fd);
int    parse_map(BRD *board, const char *path);
//utils
int     is_white_space(char c);
int     is_empty_line(char *str);
char    *strjoin(const char *s1, const char *s2);

int     is_empty_line(char *str);
int     is_valid_map(BRD *board, char **map);
char    *strjoin(const char *s1, const char *s2);
char    *get_next_line(int fd);

#endif