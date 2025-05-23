#include "../../include/parsing.h"

char    **realloc_map(char **map, int nbrlines)
{
    char    **ret;

    if (!(ret = malloc(sizeof(char*) * (nbrlines + 1))))
        return (NULL);
    for (int i = 0; i != nbrlines; i++)
        ret[i] = map[i];
    return (ret);
}

char    **read_map(int fd)
{
    char    **map;
    int     nbrlines = 0;
    char    *newline = get_next_line(fd);

    while (newline){
        map = realloc_map(map, nbrlines);
        map[nbrlines] = newline;
        nbrlines++;
        newline = get_next_line(fd);
    }
    return (map);
}

void    parse_map()
{
    char    buf[1];

    int     fd;
    int     wc = 0;

    char    **maptest;

    if ((fd = open("./test", O_RDONLY)) == -1)
        return;
    maptest = read_map(fd);
    close(fd);
}