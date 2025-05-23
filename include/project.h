#ifndef PROJECT_H
#define PROJECT_H

#define POSX 0
#define POSY 1

typedef struct
{
    char **data;
    int width;
    int height;
	int poschar[2];
	int posmch[2];
} BRD;

#include "character.h"
#include "board.h"
#include "mouche.h"
#include "parsing.h"

#endif
