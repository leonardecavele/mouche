#include "../include/project.h"

int main()
{
    BRD board;

    if (!parse_map(&board)) {
        fprintf(stderr, "Parsing Error. Check map validity\n");
        return (1);
    }
    return (0);
}