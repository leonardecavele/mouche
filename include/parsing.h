#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define MAP_PATH "../../maps/map1.txt"

int     is_empty_line(char *str);
char    *strjoin(const char *s1, const char *s2);
char    *get_next_line(int fd);

#endif