#include "../../include/parsing.h"

char    *strjoin(const char *s1, const char *s2)
{
    char    *dst;
    int     i, j = 0;

    if (!s1 || ! s2)
        return (NULL);
    if (!(dst = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1))))
        return (NULL);
    for (i = 0; s1[i]; i++) {
        dst[j] = s1[i];
        j++;
    }
    for (i = 0; s2[i]; i++) {
        dst[j] = s2[i];
        j++;
    }
    dst[j] = '\0';
    return (dst);
}