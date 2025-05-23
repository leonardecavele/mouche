#include "../../include/project.h"

char    **realloc_map(char **map, int nbrlines)
{
    char    **ret;

    if (!(ret = malloc(sizeof(char*) * (nbrlines + 1))))
        return (NULL);
    for (int i = 0; i != nbrlines; i++)
        ret[i] = map[i];
    return (ret);
}

char    **read_map(BRD *board, int fd)
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
    board->height = nbrlines;
    if (nbrlines)
        board->width = strlen(map[0]);
    else
        board->width = 0;
    return (map);
}

void    parse_map(BRD *board)
{
    char    buf[1];
    int     fd;

    if ((fd = open(MAP_PATH, O_RDONLY)) == -1)
        return;
    board->data = read_map(board, fd);
    close(fd);
    if (!is_map_valid(board, maptest))
        printf("error, map is not valid\n");
    else
        printf("success, map is valid\n");
}

int main()
{
    BRD board;

    parse_map(&board);
    return (0);
}