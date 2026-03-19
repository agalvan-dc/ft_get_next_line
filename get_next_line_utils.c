
#include "get_next_line.h"

size_t	ft_strlen(char *cad)
{
	size_t	len;

	len = 0;
	while (cad[len])
		len++;
	return (len);
}

char    *ft_strchr(const char *s, int c)
{
    char    *p;
    int i;

    i = 0;
    p = (char *)s;
    c = (char)c;
    if (!p || !p[0])
        return (NULL);
    while (p[i] && p[i] != c)
    {
        if (p[i] == c)
            return (&p[i]);
        i++;
    }
    if (p[i] == c)
        return (&p[i]);
    return (NULL);
}

char	*ft_accum(char *c, char *s)
{
    size_t  i;
    size_t  j;
    char    *new;

    j = 0;
    i = 0;
    new = malloc(sizeof(char) * (ft_strlen(c) + ft_strlen(s) + 1));
    if (!new)
        return (NULL);
    while (*s[i])
    {
            new[i] = (*s)[i];
            i++;
    }
    free(*s);
    while (c[j])
        new[i++] = c[j++];
    new[i] = '\0';
    return (new);
}
