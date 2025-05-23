#include "../../include/project.h"

void    count_spechar(BRD *board, char *str, int refline, int *nbrchar, int *nbrmch)
{
    for (int i = 0; str[i]; i++){
        if (str[i] == '#'){
            (*nbrchar)++;
            board->poschar[0] = i;
            board->poschar[1] = refline;
        }
        else if (str[i] == '*'){
            (*nbrmch)++;
            board->posmch[0] = i;
            board->posmch[1] = refline;
        }
    }
}

int     is_line_valid(char *str, int width)
{
    if (str[0] != '|' || str[width - 1] != '|')
        return (0);
    for (int i = 1; i < (width - 1); i++)
        if (str[i] != ' ' && str[i] != '#' && str[i] != '*')
            return (0);
    return (1);
}

int     is_minus_only(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != '-')
            return (0);
    return (1);
}

int     is_valid_map(BRD *board, char **map)
{
    int i = 0, nbrchar = 0, nbrmch = 0;

    if (board->height < 3)
        return (0);
    while (i < board->height && is_empty_line(map[i]))
        i++;
    if (i == board->height)
        return (0);
    if (!is_minus_only(map[i]))
        return (0);
    board->width = strlen(map[i]);
    if (board->width < 3)
        return (0);
    i++;
    while (i < board->height && !is_minus_only(map[i])){
        if (!is_line_valid(map[i], board->width))
            return (0);
        count_spechar(board, map[i], i, &nbrchar, &nbrmch);
        i++;
    }
    if (nbrchar != 1 || nbrmch != 1)
        return (0);
    if (i == board->height || !is_minus_only(map[i]) || strlen(map[i]) != board->width)
        return (0);
    i++;
    while (i < board->height && is_empty_line(map[i]))
        i++;
    if (i != board->height)
        return (0);
    return (1);
}