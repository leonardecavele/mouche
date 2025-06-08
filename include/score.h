#ifndef SCORE_H
#define SCORE_H

extern char new_player[4];
extern int new_move_count;
extern int new_score_count;

extern char best_player[4];
extern int best_move_count;
extern int best_score_count;

void win(char *path, char *c, BRD *board);
void parse_score();
void read_score(FILE *score);
void write_score(char *c);
void get_name();
void to_upper(char *str);

#endif
