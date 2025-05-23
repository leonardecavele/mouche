#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define MAP_PATH "../../maps/map"
# define MAP_SIZEMAX 9999

char    *strjoin(const char *s1, const char *s2);

#endif