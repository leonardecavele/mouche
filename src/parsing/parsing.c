#include "../../include/parsing.h"

parse_map()
{
    char    buf[1];

    int     fd;
    int     wc = 0;

    if (fd = open(MAP_PATH, O_RDONLY) == -1)
        return (1);

    if (read(MAP_PATH, buf, sizeof(char)) == -1)
        return (1);
}