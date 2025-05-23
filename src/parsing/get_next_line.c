#include "../../include/parsing.h"

void    *error(char *ret)
{
    free(ret);
    return (NULL);
}

char    *get_next_line(int fd)
{
    char    buf[2] = {0,0};
    char    *ret;
    char    *tmp;
    int     retread = 1;

    if (!(ret = malloc(sizeof(char))))
        return (NULL);
    ret[0] = 0;
    while (buf[0] != '\n' && retread){
        if ((retread = read(fd, buf, sizeof(char))) == -1)
            return error(ret);
        if (buf[0] != '\n' && retread){
            if (!(tmp = strjoin(ret, buf)))
                return error(ret);
            free(ret);
            ret = tmp;
            tmp = NULL;
        }
    }
    if (buf[0] == '\n' || (!retread && ret[0]))
        return (ret);
    else
        return (NULL);
}