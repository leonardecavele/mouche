#include "../../include/parsing.h"

char    *strjoin(const char *s1, const char *s2)
{
    char    *dst;
    int     i, j = 0;

    if (!s1 || ! s2)
        return (null);
    if (!(dst = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1))))
        return (null);
    for (i = 0; s1[i]; i++) {
        dst[j] = s1[i];
        j++;
    }
    for (i = 0; s2[i]; i++) {
        dst[j] = s2[i];
        j++;
    }
    return (dst);
}

int main()
{
    char    *s1 = "salut";
    char    *s2 = "bonjour";
    char    *s3 = strjoin(s1, s2);
    printf("%s, %s, %s\n", s1, s2, s3);
    return (0);
}