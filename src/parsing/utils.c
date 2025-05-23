#include "../../include/project.h"

int     is_white_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v' || c == '\f')
        return (1);
    return (0);
}

int     is_empty_line(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!iswhitespace(str[i]))
            return (0);
    return (1);
}

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