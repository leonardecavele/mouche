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
        if (!is_empty_line(newline)){
            map = realloc_map(map, nbrlines);
            map[nbrlines] = newline;
            nbrlines++;
        }
        newline = get_next_line(fd);
    }
    board->height = nbrlines;
    return (map);
}

int    parse_map(BRD *board, const char *path)
{
    int     fd;

    if ((fd = open(path, O_RDONLY)) == -1)
        return(0);
    board->data = read_map(board, fd);
    close(fd);
    if (!is_valid_map(board, board->data))
        return (0);
    return (1);
}

// int main()
// {
//     BRD board;

//     if (!parse_map(&board))
//         printf("Error\n");
//     else{    
//         printf("Success\n");
//         for (int i = 0; i < board.height; i++)
//             printf("%s\n", board.data[i]);
//         printf("width: %d\n", board.width);
//         printf("height: %d\n", board.height);
//         printf("poschar: (x)%d (y)%d\n", board.poschar[0], board.poschar[1]);
//         printf("posmch: (x)%d (y)%d\n", board.posmch[0], board.posmch[1]);

//     }
//     return (0);
// }
