#include "../../include/parsing.h"

void    *error(char *ret)
{
    free(ret);
    return (null);
}

char    *get_next_line(int fd)
{
    char    buf[1];
    char    *ret;

    if (!(ret = malloc(sizeof(char))))
        return (null);
    if (read(MAP_PATH, buf, sizeof(char)) == -1)
        return error();
}